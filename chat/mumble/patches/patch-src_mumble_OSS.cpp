$NetBSD: patch-src_mumble_OSS.cpp,v 1.3 2020/10/16 07:42:48 nia Exp $

Make device iteration work with NetBSD's OSS compat layer.

XXX: Fix this in libossaudio.

--- src/mumble/OSS.cpp.orig	2020-10-04 20:25:02.000000000 +0000
+++ src/mumble/OSS.cpp
@@ -128,9 +128,46 @@ void OSSOutputRegistrar::setDeviceChoice
 OSSEnumerator::OSSEnumerator() {
 	qhInput.insert(QString(), QLatin1String("Default OSS Device"));
 	qhOutput.insert(QString(), QLatin1String("Default OSS Device"));
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+	qhDevices.insert(QString(), QLatin1String("/dev/audio"));
+#else
 	qhDevices.insert(QString(), QLatin1String("/dev/dsp"));
+#endif
+
+#if defined(__NetBSD__)
+	for (int i=0;i< 32;i++) {
+		char audiodevname[32];
+		int fd;
+		oss_audioinfo ainfo;
+
+		ainfo.dev = i;
+		snprintf(audiodevname, sizeof(audiodevname), "/dev/audio%d", i);
+		if ((fd = open(audiodevname, O_RDWR)) == -1) {
+			break;
+		}
+		if (ioctl(fd, SNDCTL_AUDIOINFO, &ainfo) == -1) {
+			close(fd);
+			qWarning("OSSEnumerator: SNDCTL_AUDIOINFO failed for device %d", i);
+			continue;
+		}
+
+		close(fd);
 
-#if (SOUND_VERSION >= 0x040002)
+		QString handle = QLatin1String(ainfo.handle);
+		QString name = QLatin1String(ainfo.name);
+		QString device = QLatin1String(ainfo.devnode);
+
+		if (ainfo.caps & PCM_CAP_HIDDEN)
+			continue;
+
+		qhDevices.insert(device, device);
+
+		if (ainfo.caps & PCM_CAP_INPUT)
+			qhInput.insert(device, name);
+		if (ainfo.caps & PCM_CAP_OUTPUT)
+			qhOutput.insert(device, name);
+	}
+#elif (SOUND_VERSION >= 0x040002) && !defined(__NetBSD__)
 	int mixerfd = open("/dev/mixer", O_RDWR, 0);
 	if (mixerfd == -1) {
 		qWarning("OSSEnumerator: Failed to open /dev/mixer");
