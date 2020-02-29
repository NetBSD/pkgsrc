$NetBSD: patch-src_output_plugins_SolarisOutputPlugin.cxx,v 1.2 2020/02/29 08:58:33 wiz Exp $

Allow this plugin to be also used on NetBSD.
https://github.com/MusicPlayerDaemon/MPD/pull/775

--- src/output/plugins/SolarisOutputPlugin.cxx.orig	2019-10-16 09:58:36.000000000 +0000
+++ src/output/plugins/SolarisOutputPlugin.cxx
@@ -22,22 +22,23 @@
 #include "system/FileDescriptor.hxx"
 #include "system/Error.hxx"
 
+#include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
 
-#ifdef __sun
+#if defined(__sun)
 #include <sys/audio.h>
 #include <sys/stropts.h>
+#elif defined(__NetBSD__)
+#include <sys/audioio.h>
 #else
 
 /* some fake declarations that allow build this plugin on systems
    other than Solaris, just to see if it compiles */
 
-#include <sys/ioctl.h>
-
 #ifndef I_FLUSH
 #define I_FLUSH 0
 #endif
@@ -147,7 +148,11 @@ SolarisOutput::Play(const void *chunk, s
 void
 SolarisOutput::Cancel() noexcept
 {
+#if defined(AUDIO_FLUSH)
+	ioctl(fd.Get(), AUDIO_FLUSH);
+#elif defined(I_FLUSH)
 	ioctl(fd.Get(), I_FLUSH);
+#endif
 }
 
 const struct AudioOutputPlugin solaris_output_plugin = {
