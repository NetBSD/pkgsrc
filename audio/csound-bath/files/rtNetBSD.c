/* 
   --- rtNetBSD.c ---

   Native NetBSD audio support.

   Ben Collver, collver@linuxfreemail.com
*/

#include <sys/types.h>
#include <sys/audioio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "cs.h"
#include "soundio.h"
#include "rtNetBSD.h"

static int dspfd;

static  int     ishift = 0, oshift = 0, oMaxLag;
extern  long    nrecs;
        long    inrecs;
extern  OPARMS  O;
extern int Linefd;
#ifdef PIPES
extern FILE* Linepipe;
#  define _pclose pclose
#endif

static int getshift(int dsize)  /* turn sample- or frame-size into shiftsize */
{
  switch(dsize) {
  case 1:  return(0);
  case 2:  return(1);
  case 4:  return(2);
  case 8:  return(3);
  default: die("rtaudio: illegal dsize");
	return(-1);		/* Not reached */
        }
}
  

void display_audio_info(
	int fd,
	const char *message,
	audio_info_t *info)
{
	audio_encoding_t encoding;
	char *encoding_name;

	encoding.index = info->play.encoding;
	if (ioctl(fd, AUDIO_GETENC, &encoding) == -1) {
		asprintf(&encoding_name, "%d", info->play.encoding);
	} else {
		encoding_name = strdup(encoding.name);
	}
	printf("%-9s\n", message);
	printf("         info.play.precision = %d\n", info->play.precision);
	printf("         info.play.encoding = %s\n", encoding_name);
	printf("         info.play.channels = %d\n", info->play.channels);
	printf("         info.play.sample_rate = %d\n", info->play.sample_rate);
	printf("         info.blocksize = %d\n\n", info->blocksize);
	free(encoding_name);
}

void setsndparms(
	int fd,
	int format,
	int nchnls,
	MYFLT esr, 
	unsigned bufsiz)
{
	audio_info_t info;
	int count;
	int frag_size;

	AUDIO_INITINFO(&info);

	switch (format) {
	case AE_UNCH:
		info.play.precision = 8;
		info.play.encoding = AUDIO_ENCODING_ULINEAR;
		break;
	case AE_CHAR:
		info.play.precision = 8;
		info.play.encoding = AUDIO_ENCODING_SLINEAR;
		break;
	case AE_ULAW:
		info.play.precision = 8;
		info.play.encoding = AUDIO_ENCODING_ULAW;
		break;
	case AE_ALAW:
		info.play.precision = 8;
		info.play.encoding = AUDIO_ENCODING_ALAW;
		break;
	case AE_SHORT:
		/* audio(4) says AUDIO_ENCODING_SLINEAR uses platform's
		   byte order, so the below will automatically be BE on
		   a BE system, and LE on a LE system.  Good/Bad/Ok? */

		info.play.precision = 16;
		info.play.encoding = AUDIO_ENCODING_SLINEAR;
		break;
	case AE_LONG:
		info.play.precision = 32;
		info.play.encoding = AUDIO_ENCODING_SLINEAR;
		break;
	case AE_FLOAT:
		die("NetBSD audio does not support floating-point samples");
	default:
		die("unknown sample format");
	}

	info.play.channels = nchnls;
	info.play.sample_rate = (unsigned int) esr;

	/* set DMA buffer fragment size to Csound's output buffer size */
	/*
	 * The or'ing is ABSOLUTELY crucial to obtaining quick response
	 * of csound to MIDI input - Please don't touch this line unless
	 * you know you can do better (in terms of MIDI response)
	 * [nicb@axnet.it]
	 */
	frag_size = 16;
	count = 4;
	while (frag_size < bufsiz && count < 18) {
		frag_size <<= 1;
		count++;
	}
	count |= 0x0020000; /* Larry Troxler's Idea */
	info.blocksize = frag_size;

	/* from ossaudio.c ioctl SNDCTL_DSP_SETFRAGMENT */
	info.hiwat = ((unsigned)count >> 16) & 0x7fff;
	if (info.hiwat == 0)
		info.hiwat = 65536;

	if (ioctl(fd, AUDIO_SETINFO, &info) == -1) {
		display_audio_info(fd, "requested", &info);
		if (ioctl(fd, AUDIO_GETINFO, &info) != -1)
			display_audio_info(fd, "got", &info);
		die("unable to configure soundcard");
	}
}

int find_mixer_label(int fd, int class, const char *name)
{
	int i;
	int mclass;
	int retval = -1;
	mixer_devinfo_t info;

        for (i = 0; ; i++) {
                info.index = i;
                if (ioctl(fd, AUDIO_MIXER_DEVINFO, &info) < 0)
                        break;
		mclass = info.mixer_class;
		if ((info.index == mclass || class == mclass) &&
			!strcmp(info.label.name, name))
		{
			retval = i;
		}
        }
	return retval;
}

void setvolume(unsigned volume)
{
	int fd;
	int i;
	int output_class;
	int vol_output;
	mixer_devinfo_t info;
	mixer_ctrl_t value;

	/* volume must be between 0 and 255 */

	if ((fd = open(NETBSD_MIXER, O_WRONLY)) == -1)
		die("unable to open soundcard mixer for setting volume");

	output_class = find_mixer_label(fd, 0, "outputs");
	vol_output = find_mixer_label(fd, output_class, "master");

	if (vol_output == -1)
		die("Could not find mixer control for audio output.");


	info.index = vol_output;
	ioctl(fd, AUDIO_MIXER_DEVINFO, &info);

	value.dev = vol_output;
	value.type = info.type;
	value.un.value.num_channels = 2;
	if (ioctl(fd, AUDIO_MIXER_READ, &value) < 0) {
		value.un.value.num_channels = 1;
		if (ioctl(fd, AUDIO_MIXER_READ, &value) < 0)
			die("unable to read mixer on soundcard"); 
	}

	value.un.value.level[0] = 192;
	value.un.value.level[1] = 192;
	if (ioctl(fd, AUDIO_MIXER_WRITE, &value) < 0) {
		die("unable to set output volume on soundcard"); 
	}
}


void NetBSD_open(int nchnls, int dsize, MYFLT esr, int scale, int audio_mode)
{
	int dup;
	int wbufsiz;
	int audio_props;
	audio_device_t device_info;
#ifdef USE_SETSCHEDULER
	extern void setscheduler(void);
#endif

	oMaxLag = O.oMaxLag;        /* import DAC setting from command line   */
	if (oMaxLag <= 0)           /* if DAC sampframes ndef in command line */
		oMaxLag = IODACSAMPS;     /* use the default value */
	wbufsiz = oMaxLag * O.insampsiz;
	switch (audio_mode) {
	case NETBSD_RECORD:
		if ((dspfd = open(NETBSD_SAMPLER, O_RDONLY)) == -1)
			die("error while opening soundcard for audio input");
		setsndparms(dspfd, O.informat, nchnls, esr, wbufsiz);
		ishift = getshift(dsize);  
		break;
	case NETBSD_PLAY:
		if ((dspfd = open(NETBSD_SAMPLER, O_WRONLY)) == -1) {
			perror("foo");
			die("error while opening soundcard for audio output");
		}
		setsndparms(dspfd, O.outformat, nchnls, esr, wbufsiz);
		/* 'oshift' is not currently used by the Linux driver, but... */
		oshift = getshift(nchnls * dsize);
		break;
	case NETBSD_DUPLEX:
		if ((dspfd = open(NETBSD_SAMPLER, O_RDWR)) == -1) 
			die("error during soundcard duplex mode query:");
		ioctl(dspfd, AUDIO_GETPROPS, &audio_props);
		if (!(audio_props | AUDIO_PROP_FULLDUPLEX))
			die("hardware does not support full duplex mode");
		setsndparms(dspfd, O.outformat, nchnls, esr, wbufsiz);
		if (ioctl(dspfd, AUDIO_SETFD, audio_props) == -1)
			die("error setting hardware to full duplex mode");
		/* are these functions both required? */
		oshift = getshift(nchnls * dsize);
		ishift = getshift(dsize);
		break;
	default:
		fprintf(stderr, "mode specification error in NetBSD_open: ");
		fprintf(stderr, "unknown argument %d\n", audio_mode);
		exit(1);
	}

	ioctl(dspfd, AUDIO_GETDEV, &device_info);
	fprintf(stderr, "NetBSD audio info: %s, %s, %s\n",
		device_info.name,
		device_info.version,
		device_info.config);
#ifdef USE_SETSCHEDULER
	setscheduler();
#endif
}

int rtrecord(char *inbuf, int nbytes) /* get samples from ADC */
{
    /*  J. Mohr  1995 Oct 17 */
    if ( (nbytes = read(dspfd, inbuf, nbytes)) == -1 )
      die("error while reading DSP device for audio input");
    return(nbytes);
}

void rtplay(char *outbuf, int nbytes) /* put samples to DAC  */
    /* N.B. This routine serves as a THROTTLE in Csound Realtime Performance, */
    /* delaying the actual writes and return until the hardware output buffer */
    /* passes a sample-specific THRESHOLD.  If the I/O BLOCKING functionality */
    /* is implemented ACCURATELY by the vendor-supplied audio-library write,  */
    /* that is sufficient.  Otherwise, requires some kind of IOCTL from here. */
    /* This functionality is IMPORTANT when other realtime I/O is occurring,  */
    /* such as when external MIDI data is being collected from a serial port. */
    /* Since Csound polls for MIDI input at the software synthesis K-rate     */
    /* (the resolution of all software-synthesized events), the user can      */
    /* eliminate MIDI jitter by requesting that both be made synchronous with */
    /* the above audio I/O blocks, i.e. by setting -b to some 1 or 2 K-prds.  */
{
        long sampframes = nbytes >> oshift;
        /*  J. Mohr  1995 Oct 17 */
        if (write(dspfd, outbuf, nbytes) < nbytes)
            printf("/dev/audio: couldn't write all bytes requested\n");
        nrecs++;
}

void rtclose(void)              /* close the I/O device entirely  */
{                               /* called only when both complete */
    /*  J. Mohr  1995 Oct 17 */
    if (close(dspfd) == -1)
      die("unable to close DSP device");
    if (O.Linein) {
#ifdef PIPES
      if (O.Linename[0]=='|') _pclose(Linepipe);
      else
#endif
        if (strcmp(O.Linename, "stdin")!=0) close(Linefd);
    }
}
