$NetBSD: patch-oawk_Makefile.mk,v 1.1 2011/11/23 22:50:25 cheusov Exp $

# Fix for make -jN
--- oawk/Makefile.mk.orig	2004-10-02 18:23:20.000000000 +0000
+++ oawk/Makefile.mk
@@ -75,14 +75,14 @@ install: all
 	$(STRIP) $(ROOT)$(DEFBIN)/oawk
 	$(MANINST) -c -m 644 oawk.1 $(ROOT)$(MANDIR)/man1/oawk.1
 
-awk.g.o: awk.def
-awk.g.o: awk.def
-awk.lx.o: awk.def
-b.o: awk.def
-lib.o: awk.def
-main.o: awk.def
-parse.o: awk.def
-proc.o: awk.def
-proctab.o: awk.def
-run.o: awk.def
-tran.o: awk.def
+awk.g.o:   awk.def awk.h
+awk.g.o:   awk.def awk.h
+awk.lx.o:  awk.def awk.h
+b.o:       awk.def awk.h
+lib.o:     awk.def awk.h
+main.o:    awk.def awk.h
+parse.o:   awk.def awk.h
+proc.o:    awk.def awk.h
+proctab.o: awk.def awk.h
+run.o:     awk.def awk.h
+tran.o:    awk.def awk.h
