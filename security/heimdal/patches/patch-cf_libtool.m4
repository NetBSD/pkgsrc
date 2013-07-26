$NetBSD: patch-cf_libtool.m4,v 1.1 2013/07/26 12:40:06 ryoon Exp $

* GNU/kFreeBSD parts: use host of Debian GNU/kFreeBSD 7.0.

--- cf/libtool.m4.orig	2012-01-11 13:03:55.000000000 +0000
+++ cf/libtool.m4
@@ -1268,7 +1268,7 @@ ia64-*-hpux*)
   rm -rf conftest*
   ;;
 
-x86_64-*kfreebsd*-gnu|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
+x86_64-*kfreebsd*-gnu|x86_64-*-gnukfreebsd*|x86_64-*linux*|ppc*-*linux*|powerpc*-*linux*| \
 s390*-*linux*|s390*-*tpf*|sparc*-*linux*)
   # Find out which ABI we are using.
   echo 'int i;' > conftest.$ac_ext
@@ -1276,7 +1276,7 @@ s390*-*linux*|s390*-*tpf*|sparc*-*linux*
     case `/usr/bin/file conftest.o` in
       *32-bit*)
 	case $host in
-	  x86_64-*kfreebsd*-gnu)
+	  x86_64-*kfreebsd*-gnu|x86_64-*-gnukfreebsd*)
 	    LD="${LD-ld} -m elf_i386_fbsd"
 	    ;;
 	  x86_64-*linux*)
@@ -1295,7 +1295,7 @@ s390*-*linux*|s390*-*tpf*|sparc*-*linux*
 	;;
       *64-bit*)
 	case $host in
-	  x86_64-*kfreebsd*-gnu)
+	  x86_64-*kfreebsd*-gnu|x86_64-*-gnukfreebsd*)
 	    LD="${LD-ld} -m elf_x86_64_fbsd"
 	    ;;
 	  x86_64-*linux*)
