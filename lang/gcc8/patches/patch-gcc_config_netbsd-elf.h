$NetBSD: patch-gcc_config_netbsd-elf.h,v 1.2 2018/11/10 11:45:27 mrg Exp $

Link PIE executables with crtbeginS/crtendS on NetBSD.
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=87221

Add NETBSD_SUBTARGET_EXTRA_SPECS and NETBSD_LINK_LD_ELF_SO_SPEC.

--- gcc/config/netbsd-elf.h.orig	2018-01-03 10:03:58.000000000 +0000
+++ gcc/config/netbsd-elf.h	2018-11-10 06:47:49.835868835 +0000
@@ -40,8 +40,11 @@
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
@@ -52,7 +55,10 @@
    C++ file-scope static objects deconstructed after exiting "main".  */
 
 #define NETBSD_ENDFILE_SPEC	\
-  "%{!shared:crtend%O%s} %{shared:crtendS%O%s} \
+  "%{!shared:                   \
+    %{!pie:crtend%O%s}          \
+    %{pie:crtendS%O%s}}         \
+   %{shared:crtendS%O%s}        \
    %:if-exists(crtn%O%s)"
 
 #undef ENDFILE_SPEC
@@ -67,6 +73,9 @@
 
    Target-specific code must provide the %(netbsd_entry_point) spec.  */
 
+#define NETBSD_LINK_LD_ELF_SO_SPEC \
+  "%{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}"
+
 #define NETBSD_LINK_SPEC_ELF \
   "%{assert*} %{R*} %{rpath*} \
    %{shared:-shared} \
@@ -81,6 +90,17 @@
        -dynamic-linker /usr/libexec/ld.elf_so} \
      %{static:-static}}"
 
+/* Provide the standard list of subtarget extra specs for NetBSD targets.  */
+#define NETBSD_SUBTARGET_EXTRA_SPECS \
+  { "netbsd_link_ld_elf_so",    NETBSD_LINK_LD_ELF_SO_SPEC }, \
+  { "netbsd_cpp_spec",          NETBSD_CPP_SPEC }, \
+  { "netbsd_link_spec",         NETBSD_LINK_SPEC_ELF }, \
+  { "netbsd_entry_point",       NETBSD_ENTRY_POINT }, \
+  { "netbsd_endfile_spec",      NETBSD_ENDFILE_SPEC },
+
+#undef SUBTARGET_EXTRA_SPECS
+#define SUBTARGET_EXTRA_SPECS   NETBSD_SUBTARGET_EXTRA_SPECS
+
 /* Use --as-needed -lgcc_s for eh support.  */
 #ifdef HAVE_LD_AS_NEEDED
 #define USE_LD_AS_NEEDED 1
