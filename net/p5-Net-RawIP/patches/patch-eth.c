$NetBSD: patch-eth.c,v 1.1 2017/08/28 09:00:13 he Exp $

Provide conditional compat define for RTF_LLINFO.

--- eth.c.orig	2007-04-03 10:59:40.000000000 +0000
+++ eth.c
@@ -203,6 +203,9 @@ int mac_disc(unsigned int addr,unsigned 
     mib[2] = 0;
     mib[3] = AF_INET;
     mib[4] = NET_RT_FLAGS;
+#if !defined(RTF_LLINFO) && defined(RTF_LLDATA) /* For netbsd-8 ++ */
+# define RTF_LLINFO RTF_LLDATA
+#endif
     mib[5] = RTF_LLINFO;
     found = 0;
     if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
