--- gcc/config/rs6000/sysv4.h.orig	2024-06-20 01:08:06.000000000 -0700
+++ gcc/config/rs6000/sysv4.h	2024-12-17 15:48:26.037567286 -0800
@@ -798,21 +798,14 @@
 #define LIB_NETBSD_SPEC "\
 -lc"
 
-#define	STARTFILE_NETBSD_SPEC "\
-ncrti.o%s crt0.o%s \
-%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
+#define	STARTFILE_NETBSD_SPEC NETBSD_STARTFILE_SPEC
 
-#define ENDFILE_NETBSD_SPEC "\
-%{!shared:crtend.o%s} %{shared:crtendS.o%s} \
-ncrtn.o%s"
+#define ENDFILE_NETBSD_SPEC NETBSD_ENDFILE_SPEC
 
 #define LINK_START_NETBSD_SPEC "\
 "
 
-#define LINK_OS_NETBSD_SPEC "\
-%{!shared: %{!static: \
-  %{rdynamic:-export-dynamic} \
-  -dynamic-linker /usr/libexec/ld.elf_so}}"
+#define LINK_OS_NETBSD_SPEC NETBSD_LINK_SPEC_ELF
 
 #define CPP_OS_NETBSD_SPEC "\
 -D__powerpc__ -D__NetBSD__ -D__KPRINTF_ATTRIBUTE__"
