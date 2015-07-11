$NetBSD: patch-lib_libedit_aclocal.m4,v 1.2 2015/07/11 04:26:57 rodent Exp $

--- lib/libedit/aclocal.m4.orig	2012-12-09 22:09:25.000000000 +0000
+++ lib/libedit/aclocal.m4
@@ -1283,7 +1283,7 @@ ia64-*-hpux*)
   rm -rf conftest*
   ;;
 
-x86_64-*kfreebsd*-gnu|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
+x86_64-*kfreebsd*-gnu|x86_64-*-kfreebsd*|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
 s390*-*linux*|s390*-*tpf*|sparc*-*linux*)
   # Find out which ABI we are using.
   echo 'int i;' > conftest.$ac_ext
@@ -1291,7 +1291,7 @@ s390*-*linux*|s390*-*tpf*|sparc*-*linux*
     case `/usr/bin/file conftest.o` in
       *32-bit*)
 	case $host in
-	  x86_64-*kfreebsd*-gnu)
+	  x86_64-*kfreebsd*-gnu|x86_64-*-kfreebsd*)
 	    LD="${LD-ld} -m elf_i386_fbsd"
 	    ;;
 	  x86_64-*linux*)
@@ -1310,7 +1310,7 @@ s390*-*linux*|s390*-*tpf*|sparc*-*linux*
 	;;
       *64-bit*)
 	case $host in
-	  x86_64-*kfreebsd*-gnu)
+	  x86_64-*kfreebsd*-gnu|x86_64-*-kfreebsd*)
 	    LD="${LD-ld} -m elf_x86_64_fbsd"
 	    ;;
 	  x86_64-*linux*)
