$NetBSD: patch-cmd_osstest_osstest.c,v 1.1 2021/05/09 08:14:52 nia Exp $

XXX: I need to implement this in libossaudio...

--- cmd/osstest/osstest.c.orig	2019-03-06 07:52:21.000000000 +0000
+++ cmd/osstest/osstest.c
@@ -524,11 +524,13 @@ test_device (int t, int flags)
 	return 1;
       }
 
+#ifdef DSP_CH_MASK
   if ((ainfo.caps & DSP_CH_MASK) == DSP_CH_MULTI)
     {
       printf ("- Skipping multi channel device\n");
       return 1;
     }
+#endif
 
   if (ainfo.pid != -1)
     {
