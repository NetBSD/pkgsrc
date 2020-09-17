$NetBSD: patch-numeric.c,v 1.1 2020/09/17 10:02:20 mrg Exp $

fix vax build.

--- numeric.c.orig	2020-06-14 23:01:25.000000000 +0000
+++ numeric.c	2020-09-17 05:44:47.431800053 +0000
@@ -1655,8 +1655,10 @@
         char* endp;
         char* copy = NULL;
 
+#if defined(NV_INF) || defined(NV_NAN)
         if ((endp = S_my_atof_infnan(aTHX_ s, negative, send, value)))
             return endp;
+#endif
 
         /* strtold() accepts 0x-prefixed hex and in POSIX implementations,
            0b-prefixed binary numbers, which is backward incompatible
