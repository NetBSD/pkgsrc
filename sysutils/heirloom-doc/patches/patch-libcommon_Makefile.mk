$NetBSD: patch-libcommon_Makefile.mk,v 1.1 2011/11/24 21:02:42 cheusov Exp $

# Fix for build failure
--- libcommon/Makefile.mk.orig	2006-01-22 18:33:32.000000000 +0000
+++ libcommon/Makefile.mk
@@ -2,7 +2,7 @@ all: libcommon.a
 
 OBJ = asciitype.o ib_alloc.o ib_close.o ib_free.o ib_getlin.o ib_getw.o \
 	ib_open.o ib_popen.o ib_read.o ib_seek.o oblok.o sfile.o strtol.o \
-	getdir.o regexpr.o gmatch.o utmpx.o memalign.o pathconf.o \
+	getdir.o regexpr.o gmatch.o memalign.o pathconf.o \
 	sigset.o signal.o sigrelse.o sighold.o sigignore.o sigpause.o \
 	getopt.o pfmt.o vpfmt.o setlabel.o setuxlabel.o pfmt_label.o sysv3.o
 libcommon.a: headers $(OBJ)
@@ -21,8 +21,7 @@ headers: CHECK
 		fi; \
 	}; \
 	one alloca; \
-	one malloc; \
-	one utmpx
+	one malloc
 
 install:
 
