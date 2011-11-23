$NetBSD: patch-nawk_Makefile.mk,v 1.1 2011/11/23 22:50:25 cheusov Exp $

# Fix for make -jN
--- nawk/Makefile.mk.orig	2005-02-09 15:58:39.000000000 +0000
+++ nawk/Makefile.mk
@@ -11,7 +11,7 @@ awk_sus: awk.g.o $(OBJ) version_sus.o
 awk_su3: awk.g.2001.o $(OBJ) version_su3.o
 	$(LD) $(LDFLAGS) awk.g.2001.o $(OBJ) version_su3.o $(LUXRE) -lm $(LCOMMON) $(LWCHAR) $(LIBS) -o awk_su3
 
-awk.g.c: awk.g.y
+y.tab.h awk.g.c: awk.g.y
 	$(YACC) -d awk.g.y
 	mv -f y.tab.c awk.g.c
 	(echo '1i'; echo '#include <inttypes.h>'; echo '.'; echo 'w';) | \
