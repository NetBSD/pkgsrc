$NetBSD: patch-gcc_config_netbsd-elf.h,v 1.1 2018/06/17 19:50:52 maya Exp $

Need NETBSD_SUBTARGET_EXTRA_SPECS for netbsd-eabi.h file.

--- gcc/config/netbsd-elf.h.orig	2017-01-01 12:07:43.000000000 +0000
+++ gcc/config/netbsd-elf.h
@@ -67,6 +67,9 @@ along with GCC; see the file COPYING3.  
 
    Target-specific code must provide the %(netbsd_entry_point) spec.  */
 
+#define NETBSD_LINK_LD_ELF_SO_SPEC \
+  "%{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}"
+
 #define NETBSD_LINK_SPEC_ELF \
   "%{assert*} %{R*} %{rpath*} \
    %{shared:-shared} \
@@ -81,6 +84,17 @@ along with GCC; see the file COPYING3.  
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
