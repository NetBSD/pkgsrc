$NetBSD: patch-gcc_config_netbsd-elf.h,v 1.1 2018/11/07 04:32:32 maya Exp $

Link PIE executables with crtbeginS/crtendS on NetBSD.
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=87221


--- gcc/config/netbsd-elf.h.orig	2018-01-03 10:03:58.000000000 +0000
+++ gcc/config/netbsd-elf.h
@@ -40,8 +40,11 @@ along with GCC; see the file COPYING3.  
        %{!p:crt0%O%s}}}		\
    %:if-exists(crti%O%s)	\
    %{static:%:if-exists-else(crtbeginT%O%s crtbegin%O%s)} \
-   %{!static: \
-     %{!shared:crtbegin%O%s} %{shared:crtbeginS%O%s}}"
+   %{!static:                   \
+     %{!shared:                 \
+       %{!pie:crtbegin%O%s}     \
+       %{pie:crtbeginS%O%s}}    \
+     %{shared:crtbeginS%O%s}}"
 
 #undef STARTFILE_SPEC
 #define STARTFILE_SPEC NETBSD_STARTFILE_SPEC
@@ -52,7 +55,10 @@ along with GCC; see the file COPYING3.  
    C++ file-scope static objects deconstructed after exiting "main".  */
 
 #define NETBSD_ENDFILE_SPEC	\
-  "%{!shared:crtend%O%s} %{shared:crtendS%O%s} \
+  "%{!shared:                   \
+    %{!pie:crtend%O%s}          \
+    %{pie:crtendS%O%s}}         \
+   %{shared:crtendS%O%s}        \
    %:if-exists(crtn%O%s)"
 
 #undef ENDFILE_SPEC
