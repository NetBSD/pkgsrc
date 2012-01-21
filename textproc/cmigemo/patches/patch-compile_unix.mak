$NetBSD: patch-compile_unix.mak,v 1.1.1.1 2012/01/21 13:38:41 obache Exp $

* honor user customized CFLAGS
* libtoolize

--- compile/unix.mak.orig	2011-02-27 10:45:40.000000000 +0000
+++ compile/unix.mak
@@ -10,7 +10,7 @@ libmigemo_SRC = $(SRC)
 libmigemo_OBJ = $(OBJ)
 
 DEFINES	=
-CFLAGS	= -O2 -Wall $(DEFINES) $(CFLAGS_MIGEMO)
+CFLAGS	+= -Wall $(DEFINES) $(CFLAGS_MIGEMO)
 LDFLAGS = $(LDFLAGS_MIGEMO)
 LIBS	= 
 
@@ -24,13 +24,13 @@ dirs:
 	done
 
 $(outdir)cmigemo$(EXEEXT): $(objdir)main.$(O) $(libmigemo_LIB)
-	$(CC) -o $@ $(objdir)main.$(O) -L. -L$(outdir) -lmigemo $(LDFLAGS)
+	${LIBTOOL} --mode=link $(CC) -o $@ $(objdir)main.$(O) -L. -L$(outdir) -lmigemo $(LDFLAGS)
 
-$(objdir)main.o: $(srcdir)main.c
-	$(CC) $(CFLAGS) -o $@ -c $<
+$(objdir)main.$(O): $(srcdir)main.c
+	${LIBTOOL} --mode=compile $(CC) $(CFLAGS) -o $@ -c $<
 
-$(objdir)%.o: $(srcdir)%.c
-	$(CC) $(CFLAGS) -o $@ -c $<
+$(objdir)%.$(O): $(srcdir)%.c
+	${LIBTOOL} --mode=compile $(CC) $(CFLAGS) -o $@ -c $<
 
 ##############################################################################
 # Install
@@ -69,7 +69,7 @@ install-dict:
 install: $(outdir)cmigemo$(EXEEXT) $(libmigemo_DSO) install-mkdir install-dict install-lib
 	$(INSTALL_DATA) $(srcdir)migemo.h $(incdir)
 	$(INSTALL_DATA) doc/README_j.txt $(docdir)
-	$(INSTALL_PROGRAM) $(outdir)cmigemo$(EXEEXT) $(bindir)
+	${LIBTOOL} --mode=install $(INSTALL_PROGRAM) $(outdir)cmigemo$(EXEEXT) $(bindir)
 
 ##############################################################################
 # Uninstall
