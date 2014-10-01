$NetBSD: patch-Makefile.SH,v 1.3 2014/10/01 07:17:02 adam Exp $

Due to bloody backward incompatible changes in recent dtrace on SunOS
postpone invocation of dtrace to later with the actual probe objects.

Ensure perldtrace.h is generated during makedepends in order to avoid
compilation problems

--- Makefile.SH.orig	2014-05-26 13:34:18.000000000 +0000
+++ Makefile.SH
@@ -225,10 +225,9 @@ dtrace_o=''
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
 
@@ -1579,7 +1578,7 @@ nokfilenack:	utilities
 
 .PHONY: clist hlist
 
-clist:	$(c)
+clist:	$(c) $(DTRACE_H)
 	echo $(c) | tr ' ' $(TRNL) >.clist
 
 hlist:  $(h)
