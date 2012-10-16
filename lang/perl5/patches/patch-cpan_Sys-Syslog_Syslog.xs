$NetBSD: patch-cpan_Sys-Syslog_Syslog.xs,v 1.1 2012/10/16 13:21:31 obache Exp $

CPAN-RT#77577: Build on Haiku-OS
 https://rt.cpan.org/Public/Bug/Display.html?id=77577

--- cpan/Sys-Syslog/Syslog.xs.orig	2012-04-25 00:18:32.000000000 +0000
+++ cpan/Sys-Syslog/Syslog.xs
@@ -39,6 +39,10 @@ static SV *ident_svptr;
 #define LOG_FAC(p)      (((p) & LOG_FACMASK) >> 3)
 #endif
 
+#ifndef LOG_PRIMASK
+#define LOG_PRIMASK	0x07
+#endif
+
 #ifndef	LOG_PRI
 #define	LOG_PRI(p)	((p) & LOG_PRIMASK)
 #endif
