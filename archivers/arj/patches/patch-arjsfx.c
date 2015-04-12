$NetBSD: patch-arjsfx.c,v 1.1 2015/04/12 16:09:27 tnn Exp $

Add patch from Debian (security_format.patch) to fix unsafe format string usage.

--- arjsfx.c.orig	2005-06-21 19:53:14.000000000 +0000
+++ arjsfx.c
@@ -214,7 +214,7 @@ static void final_cleanup(void)
   freopen(dev_con, m_w, stdout);
  #if SFX_LEVEL>=ARJSFXV
   if(ferror(stdout))
-   msg_fprintf(stderr, M_DISK_FULL);
+   msg_fprintf(stderr, "Can't write file. Disk full?");
   if(debug_enabled&&strchr(debug_opt, 't')!=NULL)
   {
    ticks=get_ticks()-ticks;
