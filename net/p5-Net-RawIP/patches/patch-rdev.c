$NetBSD: patch-rdev.c,v 1.1 2017/08/28 09:00:13 he Exp $

Provide conditional compat define for RTF_LLINFO.

--- rdev.c.orig	2007-04-03 10:59:40.000000000 +0000
+++ rdev.c
@@ -159,6 +159,9 @@ ip_rt_dev(u_int32_t addr,u_char *name)
                                 }
                                 ADVANCE(cp, sa);
                         }
+#if !defined(RTF_LLINFO) && defined(RTF_LLDATA) /* netbsd-8 ++ */
+# define RTF_LLINFO RTF_LLDATA
+#endif
    if(!(rtm->rtm_flags & RTF_LLINFO) && (rtm->rtm_flags & RTF_HOST)) 
      mask = 0xffffffff;   
      if(!mask && dest && (dest != local)) continue;
