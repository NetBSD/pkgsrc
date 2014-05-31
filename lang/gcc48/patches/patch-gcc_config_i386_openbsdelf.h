$NetBSD: patch-gcc_config_i386_openbsdelf.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/config/i386/openbsdelf.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/i386/openbsdelf.h
@@ -97,10 +97,13 @@ along with GCC; see the file COPYING3.  
    %{shared:-shared} %{R*} \
    %{static:-Bstatic} \
    %{!static:-Bdynamic} \
+   %{rdynamic:-export-dynamic} \
    %{assert*} \
    -dynamic-linker /usr/libexec/ld.so"
 
 #undef STARTFILE_SPEC
+
+#define SUBTARGET32_DEFAULT_CPU "i486"
 #define STARTFILE_SPEC "\
 	%{!shared: %{pg:gcrt0%O%s} %{!pg:%{p:gcrt0%O%s} %{!p:crt0%O%s}} \
 	crtbegin%O%s} %{shared:crtbeginS%O%s}"
