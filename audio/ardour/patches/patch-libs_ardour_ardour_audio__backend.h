$NetBSD: patch-libs_ardour_ardour_audio__backend.h,v 1.1 2021/09/11 16:33:11 nia Exp $

NetBSD and Solaris kernels both prefer 48000 to limit in-kernel
resampling.

--- libs/ardour/ardour/audio_backend.h.orig	2021-08-13 16:20:07.000000000 +0000
+++ libs/ardour/ardour/audio_backend.h
@@ -370,7 +370,11 @@ public:
 	 */
 	virtual float default_sample_rate () const
 	{
+#if defined(__NetBSD__) || defined(__sun)
+		return 48000.0;
+#else
 		return 44100.0;
+#endif
 	}
 
 	/** Returns a collection of uint32 identifying buffer sizes that are
