$NetBSD: patch-libcommon_Makefile.mk,v 1.2 2011/11/26 16:29:38 cheusov Exp $

# Fixes for build failure
--- libcommon/Makefile.mk.orig	2006-01-22 18:33:32.000000000 +0000
+++ libcommon/Makefile.mk
@@ -2,9 +2,10 @@ all: libcommon.a
 
 OBJ = asciitype.o ib_alloc.o ib_close.o ib_free.o ib_getlin.o ib_getw.o \
 	ib_open.o ib_popen.o ib_read.o ib_seek.o oblok.o sfile.o strtol.o \
-	getdir.o regexpr.o gmatch.o utmpx.o memalign.o pathconf.o \
+	getdir.o regexpr.o gmatch.o memalign.o pathconf.o \
 	sigset.o signal.o sigrelse.o sighold.o sigignore.o sigpause.o \
 	getopt.o pfmt.o vpfmt.o setlabel.o setuxlabel.o pfmt_label.o sysv3.o
+${OBJ} : headers
 libcommon.a: headers $(OBJ)
 	$(AR) -rv $@ $(OBJ)
 	$(RANLIB) $@
@@ -21,8 +22,7 @@ headers: CHECK
 		fi; \
 	}; \
 	one alloca; \
-	one malloc; \
-	one utmpx
+	one malloc
 
 install:
 
