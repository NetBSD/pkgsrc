$NetBSD: patch-src_plugins_sun_ao__sun.c,v 1.2 2020/05/28 19:30:45 nia Exp $

- Fix device selection on NetBSD.
- Support 24-bit playback on NetBSD.

--- src/plugins/sun/ao_sun.c.orig	2016-11-14 08:03:30.000000000 +0000
+++ src/plugins/sun/ao_sun.c
@@ -78,6 +78,9 @@ typedef struct ao_sun_internal {
 	char *dev;
         int id;
 	int fd;
+	int linear24;
+	void *convbuf;
+	size_t convbuf_sz;
 } ao_sun_internal;
 
 
@@ -160,7 +163,11 @@ int ao_plugin_open(ao_device *device, ao
 
         if(internal->dev==NULL){
           char buf[80];
-          sprintf(buf,"/dev/sound/%d",internal->id);
+#ifdef __sun
+          snprintf(buf,sizeof(buf),"/dev/audio%d",internal->id);
+#else
+          snprintf(buf,sizeof(buf),"/dev/sound/%d",internal->id);
+#endif
           internal->dev=strdup(buf);
         }
 
@@ -172,7 +179,12 @@ int ao_plugin_open(ao_device *device, ao
 	info.mode = AUMODE_PLAY;
 #endif
 	info.play.encoding = AUDIO_ENCODING_SLINEAR;
-	info.play.precision = format->bits;
+	if (format->bits == 24) {
+		info.play.precision = 32;
+		internal->linear24 = 1;
+	} else {
+		info.play.precision = format->bits;
+	}
 	info.play.sample_rate = format->rate;
 	info.play.channels = device->output_channels;
 
@@ -198,8 +210,46 @@ int ao_plugin_play(ao_device *device, co
 		uint_32 num_bytes)
 {
 	ao_sun_internal *internal = (ao_sun_internal *) device->internal;
+	void *out;
+
+	/* convert 24-bit linear to 32-bit linear for NetBSD compat */
+	if (internal->linear24) {
+		unsigned char *srcp = (unsigned char *)output_samples;
+		size_t nsamples = num_bytes / 3;
+		size_t bufsz = nsamples * 4;
+		sint_32 *outp, temp;
+
+		if (internal->convbuf_sz < bufsz) {
+			internal->convbuf = realloc(internal->convbuf, bufsz);
+			if (!internal->convbuf)
+				return 1;
+			internal->convbuf_sz = bufsz;
+		}
+		outp = internal->convbuf;
+		if (device->driver_byte_format != AO_FMT_BIG) {
+			while (nsamples--) {
+				temp = (((sint_32)srcp[0]) << 8);
+				temp = temp | (((sint_32)srcp[1]) << 16);
+				temp = temp | (((sint_32)srcp[2]) << 24);
+				*(outp++) = temp;
+				srcp += 3;
+			}
+		} else {
+			while (nsamples--) {
+				temp = (((sint_32)srcp[0]) << 24);
+				temp = temp | (((sint_32)srcp[1]) << 16);
+				temp = temp | (((sint_32)srcp[2]) << 8);
+				*(outp++) = temp;
+				srcp += 3;
+			}
+		}
+		num_bytes = bufsz;
+		out = internal->convbuf;
+	} else {
+		out = (void *)output_samples;
+	}
 
-	if (write(internal->fd, output_samples, num_bytes) < 0)
+	if (write(internal->fd, out, num_bytes) < 0)
 		return 0;
 	else
 		return 1;
@@ -224,6 +274,7 @@ void ao_plugin_device_clear(ao_device *d
 
         if(internal->dev)
           free(internal->dev);
+	free(internal->convbuf);
 	free(internal);
         device->internal=NULL;
 }
