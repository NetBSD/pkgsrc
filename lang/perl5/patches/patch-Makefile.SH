$NetBSD: patch-Makefile.SH,v 1.1 2014/01/04 15:10:05 richard Exp $
due to bloody backward incompatible changes in recent dtrace on SunOS
postpone invocation of dtrace to later with the actual probe objects.

--- Makefile.SH.orig	2013-08-12 02:44:47.000000000 +0000
+++ Makefile.SH
@@ -234,10 +234,9 @@ dtrace_o=''
 minidtrace_o=''
 case "$usedtrace" in
 define|true)
-	dtrace_h='perldtrace.h' 
-	$dtrace -G -s perldtrace.d -o perldtrace.tmp >/dev/null 2>&1 \
-		&& rm -f perldtrace.tmp && dtrace_o='perldtrace$(OBJ_EXT)' \
-		&& minidtrace_o='miniperldtrace$(OBJ_EXT)'
+	dtrace_h='perldtrace.h'
+	dtrace_o='perldtrace$(OBJ_EXT)'
+	minidtrace_o='miniperldtrace$(OBJ_EXT)'
 	;;
 esac
 
