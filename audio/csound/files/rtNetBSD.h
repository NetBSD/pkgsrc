/* rtNetBSD.h */

#ifndef _RTNETBSD_INCLUDED
#define _RTNETBSD_INCLUDED

#define NETBSD_RECORD 0
#define NETBSD_PLAY   1
#define NETBSD_DUPLEX 2

#define USE_SETSCHEDULER

#define NETBSD_MIXER "/dev/mixer0"
#define NETBSD_SAMPLER "/dev/sound0"

#define recopen(a,b,c,d) NetBSD_open(a,b,c,d,NETBSD_DUPLEX)
#define playopen(a,b,c,d) NetBSD_open(a,b,c,d,NETBSD_PLAY)

extern void NetBSD_open(int, int, MYFLT, int, int);

#endif /* _RTNETBSD_INCLUDED */
