$NetBSD: patch-ARmake.inc,v 1.1.1.1 2012/05/29 16:38:01 asau Exp $

--- ARmake.inc.orig	1996-04-26 19:12:57.000000000 +0000
+++ ARmake.inc
@@ -25,14 +25,14 @@
 # | other than your home directory.      |
 # %--------------------------------------%
 #
-home = $(HOME)/ARPACK
+home = ${WRKSRC}
 #
 #  %--------------------------------------%
 #  | The platform identifier to suffix to |
 #  | the end of library names             |
 #  %--------------------------------------%
 #
-PLAT = SUN4
+# PLAT = SUN4
 #
 #  %------------------------------------------------------%
 #  | The directories to find the various pieces of ARPACK |
@@ -57,7 +57,7 @@ DIRS        = $(BLASdir) $(LAPACKdir) $(
 # | The name of the libraries to be created/linked to |
 # %---------------------------------------------------%
 #
-ARPACKLIB  = $(home)/libarpack_$(PLAT).a
+ARPACKLIB  = $(home)/libarpack.a
 LAPACKLIB = 
 BLASLIB = 
 #
@@ -101,8 +101,9 @@ ALIBS =  $(ARPACKLIB) $(LAPACKLIB) $(BLA
 # | for your system.                        |
 # %-----------------------------------------%
 #
-FC      = f77
-FFLAGS	= -O -cg89
+# Provided by pkgsrc
+# FC      = gfortran
+FFLAGS	= -O -fPIC
 
 LDFLAGS = 
 CD      = cd
@@ -112,7 +113,7 @@ ECHO    = echo
 LN      = ln
 LNFLAGS = -s
 
-MAKE    = /bin/make
+# MAKE    = /bin/make
 
 RM      = rm
 RMFLAGS = -f
