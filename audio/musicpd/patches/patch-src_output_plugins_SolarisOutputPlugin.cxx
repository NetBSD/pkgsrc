$NetBSD: patch-src_output_plugins_SolarisOutputPlugin.cxx,v 1.4 2020/04/14 12:55:04 nia Exp $

- Use AUDIO_INITINFO rather than AUDIO_GETINFO for initialization
- Don't open the device in non-blocking mode, no OS has needed this for years
- Support S8 and S32 formats

https://github.com/MusicPlayerDaemon/MPD/pull/826

--- src/output/plugins/SolarisOutputPlugin.cxx.orig	2020-04-02 15:48:56.000000000 +0000
+++ src/output/plugins/SolarisOutputPlugin.cxx
@@ -43,6 +43,7 @@
 #define I_FLUSH 0
 #endif
 
+#define AUDIO_INITINFO(v)
 #define AUDIO_GETINFO 0
 #define AUDIO_SETINFO 0
 #define AUDIO_ENCODING_LINEAR 0
@@ -93,33 +94,31 @@ SolarisOutput::Open(AudioFormat &audio_f
 	struct audio_info info;
 	int ret;
 
-	/* support only 16 bit mono/stereo for now; nothing else has
-	   been tested */
-	audio_format.format = SampleFormat::S16;
+	AUDIO_INITINFO(&info);
 
-	/* open the device in non-blocking mode */
-
-	if (!fd.Open(device, O_WRONLY|O_NONBLOCK))
-		throw FormatErrno("Failed to open %s",
-				  device);
-
-	/* restore blocking mode */
-
-	fd.SetBlocking();
+	if (!fd.Open(device, O_WRONLY))
+		throw FormatErrno("Failed to open %s", device);
 
 	/* configure the audio device */
 
-	ret = ioctl(fd.Get(), AUDIO_GETINFO, &info);
-	if (ret < 0) {
-		const int e = errno;
-		fd.Close();
-		throw MakeErrno(e, "AUDIO_GETINFO failed");
+#ifdef AUMODE_PLAY
+	info.mode = AUMODE_PLAY; /* BSD extension */
+#endif
+	info.play.encoding = AUDIO_ENCODING_LINEAR;
+	switch (audio_format.format) {
+	case SampleFormat::S8:
+		info.play.precision = 8;
+		break;
+	case SampleFormat::S16:
+		info.play.precision = 16;
+		break;
+	default:
+		info.play.precision = 32;
+		audio_format.format = SampleFormat::S32;
+		break;
 	}
-
 	info.play.sample_rate = audio_format.sample_rate;
 	info.play.channels = audio_format.channels;
-	info.play.precision = 16;
-	info.play.encoding = AUDIO_ENCODING_LINEAR;
 
 	ret = ioctl(fd.Get(), AUDIO_SETINFO, &info);
 	if (ret < 0) {
