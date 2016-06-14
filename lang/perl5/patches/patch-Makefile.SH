$NetBSD: patch-Makefile.SH,v 1.5 2016/06/14 11:47:21 jperkin Exp $

Do not generate DTrace objects for objects which do not contain DTrace probes.

--- Makefile.SH.orig	2016-05-08 13:28:35.000000000 +0000
+++ Makefile.SH
@@ -396,7 +396,7 @@ DTRACE_H = $dtrace_h
 
 DTRACE_PERLLIB_O = $dtrace_perllib_o # "dtrace -G" output for perllib_objs
 DTRACE_MINI_O    = $dtrace_mini_o    # "dtrace -G" output for common and mini
-DTRACE_MAIN_O    = $dtrace_main_o    # "dtrace -G" output for perlmain.o
+#DTRACE_MAIN_O    = $dtrace_main_o    # "dtrace -G" output for perlmain.o
 
 FIRSTMAKEFILE = $firstmakefile
 
