$NetbSD$

Carry over changes from in-tree gcc in an attempt at
making this build on NetBSD/powerpc.

--- gcc/config/rs6000/sysv4.h.orig	13 Sep 2025 23:45:31 -0000	1.1.1.15
+++ gcc/config/rs6000/sysv4.h	14 Sep 2025 00:07:22 -0000	1.16
@@ -92,6 +92,7 @@
   else if (!strcmp (rs6000_abi_name, "aixdesc"))			\
     rs6000_current_abi = ABI_AIX;					\
   else if (!strcmp (rs6000_abi_name, "freebsd")				\
+	   || !strcmp (rs6000_abi_name, "netbsd")			\
 	   || !strcmp (rs6000_abi_name, "linux"))			\
     {									\
       if (TARGET_64BIT)							\
@@ -99,8 +100,6 @@
       else								\
 	rs6000_current_abi = ABI_V4;					\
     }									\
-  else if (!strcmp (rs6000_abi_name, "netbsd"))				\
-    rs6000_current_abi = ABI_V4;					\
   else if (!strcmp (rs6000_abi_name, "openbsd"))			\
     rs6000_current_abi = ABI_V4;					\
   else if (!strcmp (rs6000_abi_name, "i960-old"))			\
@@ -576,7 +575,8 @@
     %{mcall-openbsd: -mno-eabi }}} \
 %{msdata: -msdata=default} \
 %{mno-sdata: -msdata=none} \
-%{!mbss-plt: %{!msecure-plt: %(cc1_secure_plt_default)}}" \
+%{!mbss-plt: %{!msecure-plt: %(cc1_secure_plt_default)}} \
+%(cc1_os_netbsd)" \
 GNU_USER_TARGET_CC1_SPEC
 
 /* Default starting address if specified.  */
@@ -788,28 +788,23 @@
 #define CPP_OS_LINUX_SPEC "%{pthread:-D_REENTRANT}"
 
 /* NetBSD support.  */
-#define LIB_NETBSD_SPEC "\
--lc"
+#define LIB_NETBSD_SPEC NETBSD_LIB_SPEC
 
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
 
+#define CC1_OS_NETBSD_SPEC "\
+%{cxx-isystem}"
+
 /* OpenBSD support.  */
 #ifndef	LIB_OPENBSD_SPEC
 #define LIB_OPENBSD_SPEC "%{!shared:%{pthread:-lpthread%{p:_p}%{!p:%{pg:_p}}}} %{!shared:-lc%{p:_p}%{!p:%{pg:_p}}}"
@@ -892,6 +887,7 @@
   { "link_os_openbsd",		LINK_OS_OPENBSD_SPEC },			\
   { "link_os_default",		LINK_OS_DEFAULT_SPEC },			\
   { "cc1_secure_plt_default",	CC1_SECURE_PLT_DEFAULT_SPEC },		\
+  { "cc1_os_netbsd",		CC1_OS_NETBSD_SPEC },			\
   { "link_secure_plt",		LINK_SECURE_PLT_SPEC },			\
   { "cpp_os_ads",		CPP_OS_ADS_SPEC },			\
   { "cpp_os_yellowknife",	CPP_OS_YELLOWKNIFE_SPEC },		\
