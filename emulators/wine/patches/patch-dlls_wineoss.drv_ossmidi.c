$NetBSD: patch-dlls_wineoss.drv_ossmidi.c,v 1.1 2024/11/01 14:10:47 triaxx Exp $

Add conditional include of sys/midiio.h (at least for NetBSD).

--- dlls/wineoss.drv/ossmidi.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/wineoss.drv/ossmidi.c
@@ -39,6 +39,9 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#ifdef HAVE_SYS_MIDIIO_H
+#include <sys/midiio.h>
+#endif
 #include <sys/soundcard.h>
 #include <pthread.h>
 
@@ -79,6 +82,16 @@ struct midi_src
     int                 fd;
 };
 
+#if defined(__NetBSD__)
+struct midi_info {
+    char                name[30];
+    int                 device;
+    unsigned int        capabilities;
+    int                 dev_type;
+    int                 dummies[18];
+};
+#endif
+
 static pthread_mutex_t in_buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
 
 static unsigned int num_dests, num_srcs, num_synths, seq_refs;
@@ -289,7 +302,11 @@ static int seq_open(void)
             return -1;
         }
         fcntl(fd, F_SETFD, 1); /* set close on exec flag */
+#if defined(__NetBSD__)
+        ioctl(fd, SEQUENCER_RESET);
+#else
         ioctl(fd, SNDCTL_SEQ_RESET);
+#endif
     }
     seq_refs++;
     return fd;
@@ -322,7 +339,11 @@ static UINT oss_midi_init(void)
         return -1;
 
     /* find how many Synth devices are there in the system */
+#if defined(__NetBSD__)
+    status = ioctl(fd, SEQUENCER_NRSYNTHS, &synth_devs);
+#else
     status = ioctl(fd, SNDCTL_SEQ_NRSYNTHS, &synth_devs);
+#endif
     if (status == -1)
     {
         ERR("ioctl for nr synth failed.\n");
@@ -330,7 +351,11 @@ static UINT oss_midi_init(void)
         return -1;
     }
     /* find how many MIDI devices are there in the system */
+#if defined(__NetBSD__)
+    status = ioctl(fd, SEQUENCER_NRMIDIS, &midi_devs);
+#else
     status = ioctl(fd, SNDCTL_SEQ_NRMIDIS, &midi_devs);
+#endif
     if (status == -1)
     {
         ERR("ioctl on nr midi failed.\n");
@@ -362,7 +387,11 @@ static UINT oss_midi_init(void)
         dest->caps.dwSupport = 0;
 
         sinfo.device = i;
+#if defined(__NetBSD__)
+        status = ioctl(fd, SEQUENCER_INFO, &sinfo);
+#else
         status = ioctl(fd, SNDCTL_SYNTH_INFO, &sinfo);
+#endif
         if (status == -1)
         {
             char buf[255];
@@ -420,7 +449,11 @@ static UINT oss_midi_init(void)
     for (i = 0; i < midi_devs; i++, dest++, src++)
     {
         minfo.device = i;
+#if defined(__NetBSD__)
+        status = ioctl(fd, SEQUENCER_INFO, &minfo);
+#else
         status = ioctl(fd, SNDCTL_MIDI_INFO, &minfo);
+#endif
         if (status == -1) WARN("ioctl on midi info for device %d failed.\n", i);
 
         /* Manufacturer ID. We do not have access to this with soundcard.h
@@ -510,6 +543,7 @@ NTSTATUS oss_midi_release(void *args)
     return STATUS_SUCCESS;
 }
 
+#if !defined(__NetBSD__)
 /* FIXME: this is a bad idea, it's even not static... */
 SEQ_DEFINEBUF(1024);
 
@@ -543,6 +577,7 @@ void seqbuf_dump(void)
     }
     seq_close(fd);
 }
+#endif
 
 extern const unsigned char midiFMInstrumentPatches[16 * 128];
 extern const unsigned char midiFMDrumsPatches[16 * 128];
@@ -553,7 +588,11 @@ static int midi_out_fm_load(WORD dev_id,
     int i;
 
     sbi.device = dev_id;
+#if defined(__NetBSD__)
+    sbi.key = SBI_FM_PATCH;
+#else
     sbi.key = FM_PATCH;
+#endif
 
     memset(sbi.operators + 16, 0, 16);
     for (i = 0; i < 128; i++)
@@ -592,9 +631,14 @@ static void midi_out_fm_reset(WORD dev_i
     for (i = 0; i < dest->caps.wVoices; i++)
     {
         if (voice[i].status != sVS_UNUSED)
+#if defined(__NetBSD__)
+            SEQ_MK_CHN(NOTEOFF, .device=dev_id, .channel=i, .key=voice[i].note, .velocity=64);
+        SEQ_MK_CHN(KEY_PRESSURE, .device=dev_id, .channel=i, .key=127, .pressure=0);
+#else
             SEQ_STOP_NOTE(dev_id, i, voice[i].note, 64);
         SEQ_KEY_PRESSURE(dev_id, i, 127, 0);
         SEQ_CONTROL(dev_id, i, SEQ_VOLMODE, VOL_METHOD_LINEAR);
+#endif
         voice[i].note = 0;
         voice[i].channel = -1;
         voice[i].cntMark = 0;
@@ -613,7 +657,9 @@ static void midi_out_fm_reset(WORD dev_i
     }
     extra->counter = 0;
     extra->drumSetMask = 1 << 9; /* channel 10 is normally drums, sometimes 16 also */
+#if !defined(__NetBSD__)
     SEQ_DUMPBUF();
+#endif
 }
 
 static void set_out_notify(struct notify_context *notify, struct midi_dest *dest, WORD dev_id, WORD msg,
@@ -797,7 +843,11 @@ static UINT midi_out_fm_data(WORD dev_id
             if (voice[i].status == sVS_PLAYING && voice[i].channel == chn && voice[i].note == d1)
             {
                 voice[i].status = sVS_UNUSED;
+#if defined(__NetBSD__)
+                SEQ_MK_CHN(NOTEOFF, .device=dev_id, .channel=i, .key=d1, .velocity=d2);
+#else
                 SEQ_STOP_NOTE(dev_id, i, d1, d2);
+#endif
             }
         }
         break;
@@ -809,7 +859,11 @@ static UINT midi_out_fm_data(WORD dev_id
                 if (voice[i].status == sVS_PLAYING && voice[i].channel == chn && voice[i].note == d1)
                 {
                     voice[i].status = sVS_UNUSED;
+#if defined(__NetBSD__)
+                    SEQ_MK_CHN(NOTEOFF, .device=dev_id, .channel=i, .key=d1, .velocity=64);
+#else
                     SEQ_STOP_NOTE(dev_id, i, d1, 64);
+#endif
                 }
             }
             break;
@@ -832,6 +886,13 @@ static UINT midi_out_fm_data(WORD dev_id
         TRACE("playing on voice=%d, pgm=%d, pan=0x%02X, vol=0x%02X, bender=0x%02X, note=0x%02X, vel=0x%02X\n",
               nv, channel[chn].program, channel[chn].balance, channel[chn].volume, channel[chn].bender, d1, d2);
 
+#if defined(__NetBSD__)
+        SEQ_MK_CHN(PITCH_BEND, .device=dev_id, .channel=nv, .value=channel[chn].bender);
+	SEQ_MK_CHN(CTL_CHANGE, .device=dev_id, .channel=nv, .controller=MIDI_CTRL_PAN_MSB, .value=channel[chn].balance>>7);
+	SEQ_MK_CHN(CTL_CHANGE, .device=dev_id, .channel=nv, .controller=MIDI_CTRL_PAN_LSB, .value=channel[chn].balance&0x7f);
+	SEQ_MK_CHN(CTL_CHANGE, .device=dev_id, .channel=nv, .controller=MIDI_CTRL_EXPRESSION_MSB, .value=channel[chn].expression>>7);
+	SEQ_MK_CHN(CTL_CHANGE, .device=dev_id, .channel=nv, .controller=MIDI_CTRL_EXPRESSION_LSB, .value=channel[chn].expression&0x7f);
+#else
         SEQ_SET_PATCH(dev_id, nv, IS_DRUM_CHANNEL(extra, chn) ?
                       (128 + d1) : channel[chn].program);
         SEQ_BENDER_RANGE(dev_id, nv, channel[chn].benderRange * 100);
@@ -839,6 +900,7 @@ static UINT midi_out_fm_data(WORD dev_id
         SEQ_CONTROL(dev_id, nv, CTL_PAN, channel[chn].balance);
         SEQ_CONTROL(dev_id, nv, CTL_EXPRESSION, channel[chn].expression);
         SEQ_START_NOTE(dev_id, nv, d1, d2);
+#endif
         voice[nv].status = channel[chn].sustain ? sVS_SUSTAINED : sVS_PLAYING;
         voice[nv].note = d1;
         voice[nv].channel = chn;
@@ -847,11 +909,16 @@ static UINT midi_out_fm_data(WORD dev_id
     case MIDI_KEY_PRESSURE:
         for (i = 0; i < dest->caps.wVoices; i++)
             if (voice[i].status != sVS_UNUSED && voice[i].channel == chn && voice[i].note == d1)
+#if defined(__NetBSD__)
+                SEQ_MK_CHN(KEY_PRESSURE, .device=dev_id, .channel=i, .key=d1, .pressure=d2);
+#else
                 SEQ_KEY_PRESSURE(dev_id, i, d1, d2);
+#endif
         break;
     case MIDI_CTL_CHANGE:
         switch (d1)
         {
+#if !defined(__NetBSD__)
         case CTL_BANK_SELECT: channel[chn].bank = d2; break;
         case CTL_MAIN_VOLUME: channel[chn].volume = d2; break;
         case CTL_PAN:         channel[chn].balance = d2; break;
@@ -905,6 +972,7 @@ static UINT midi_out_fm_data(WORD dev_id
                 break;
             }
             break;
+#endif
 
         case 0x78: /* all sounds off */
             /* FIXME: I don't know if I have to take care of the channel for this control? */
@@ -913,7 +981,11 @@ static UINT midi_out_fm_data(WORD dev_id
                 if (voice[i].status != sVS_UNUSED && voice[i].channel == chn)
                 {
                     voice[i].status = sVS_UNUSED;
+#if defined(__NetBSD__)
+                    SEQ_MK_CHN(NOTEOFF, .device=dev_id, .channel=i, .key=voice[i].note, .velocity=64);
+#else
                     SEQ_STOP_NOTE(dev_id, i, voice[i].note, 64);
+#endif
                 }
             }
             break;
@@ -924,7 +996,11 @@ static UINT midi_out_fm_data(WORD dev_id
                 if (voice[i].status == sVS_PLAYING && voice[i].channel == chn)
                 {
                     voice[i].status = sVS_UNUSED;
+#if defined(__NetBSD__)
+                    SEQ_MK_CHN(NOTEOFF, .device=dev_id, .channel=i, .key=voice[i].note, .velocity=64);
+#else
                     SEQ_STOP_NOTE(dev_id, i, voice[i].note, 64);
+#endif
                 }
             }
             break;
@@ -939,14 +1015,22 @@ static UINT midi_out_fm_data(WORD dev_id
     case MIDI_CHN_PRESSURE:
         for (i = 0; i < dest->caps.wVoices; i++)
             if (voice[i].status != sVS_UNUSED && voice[i].channel == chn)
+#if defined(__NetBSD__)
+                SEQ_MK_CHN(KEY_PRESSURE, .device=dev_id, .channel=i, .key=voice[i].note, .pressure=d1);
+#else
                 SEQ_KEY_PRESSURE(dev_id, i, voice[i].note, d1);
+#endif
 
         break;
     case MIDI_PITCH_BEND:
         channel[chn].bender = (d2 << 7) + d1;
         for (i = 0; i < dest->caps.wVoices; i++)
             if (voice[i].channel == chn)
+#if defined(__NetBSD__)
+                SEQ_MK_CHN(PITCH_BEND, .device=dev_id, .channel=nv, .value=channel[chn].bender);
+#else
                 SEQ_BENDER(dev_id, i, channel[chn].bender);
+#endif
         break;
     case MIDI_SYSTEM_PREFIX:
         switch (evt & 0x0F)
@@ -966,10 +1050,13 @@ static UINT midi_out_fm_data(WORD dev_id
         return MMSYSERR_NOTENABLED;
     }
 
+#if !defined(__NetBSD__)
     SEQ_DUMPBUF();
+#endif
     return MMSYSERR_NOERROR;
 }
 
+#if !defined(__NetBSD__)
 static UINT midi_out_port_data(WORD dev_id, UINT data)
 {
     struct midi_dest *dest = dests + dev_id;
@@ -1068,6 +1155,7 @@ static UINT midi_out_port_data(WORD dev_
     SEQ_DUMPBUF();
     return MMSYSERR_NOERROR;
 }
+#endif
 
 static UINT midi_out_data(WORD dev_id, UINT data)
 {
@@ -1088,8 +1176,10 @@ static UINT midi_out_data(WORD dev_id, U
     {
     case MOD_FMSYNTH:
         return midi_out_fm_data(dev_id, data);
+#if !defined(__NetBSD__)
     case MOD_MIDIPORT:
         return midi_out_port_data(dev_id, data);
+#endif
     }
 
     WARN("Technology not supported (yet) %d !\n", dest->caps.wTechnology);
@@ -1152,18 +1242,26 @@ static UINT midi_out_long_data(WORD dev_
         if (data[0] != 0xF0)
         {
             /* Send end of System Exclusive */
+#if !defined(__NetBSD__)
             SEQ_MIDIOUT(dev_id - num_synths, 0xF0);
+#endif
             WARN("Adding missing 0xF0 marker at the beginning of system exclusive byte stream\n");
         }
+#if !defined(__NetBSD__)
         for (count = 0; count < hdr->dwBufferLength; count++)
             SEQ_MIDIOUT(dev_id - num_synths, data[count]);
+#endif
         if (data[count - 1] != 0xF7)
         {
             /* Send end of System Exclusive */
+#if !defined(__NetBSD__)
             SEQ_MIDIOUT(dev_id - num_synths, 0xF7);
+#endif
             WARN("Adding missing 0xF7 marker at the end of system exclusive byte stream\n");
         }
+#if !defined(__NetBSD__)
         SEQ_DUMPBUF();
+#endif
         break;
     default:
         WARN("Technology not supported (yet) %d !\n", dest->caps.wTechnology);
@@ -1245,7 +1343,9 @@ static UINT midi_out_reset(WORD dev_id)
         /* turn off every note */
         midi_out_data(dev_id, 0x7800 | MIDI_CTL_CHANGE | chn);
         /* remove sustain on all channels */
+#if !defined(__NetBSD__)
         midi_out_data(dev_id, (CTL_SUSTAIN << 8) | MIDI_CTL_CHANGE | chn);
+#endif
     }
     dest->runningStatus = 0;
     /* FIXME: the LongData buffers must also be returned to the app */
@@ -1359,7 +1459,11 @@ static void handle_midi_data(unsigned ch
 
     for (i = 0; i < len; i += (buffer[i] & 0x80) ? 8 : 4)
     {
+#if defined(__NetBSD__)
+        if (buffer[i] != SEQOLD_MIDIPUTC) continue;
+#else
         if (buffer[i] != SEQ_MIDIPUTC) continue;
+#endif
 
         dev_id = buffer[i + 2];
         value = buffer[i + 1];
