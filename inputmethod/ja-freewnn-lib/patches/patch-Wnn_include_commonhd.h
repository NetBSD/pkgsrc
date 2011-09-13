$NetBSD: patch-Wnn_include_commonhd.h,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/include/commonhd.h.orig	2005-04-10 15:26:37.000000000 +0000
+++ Wnn/include/commonhd.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2001, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2001, 2002, 2005, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -39,7 +39,7 @@
 #include <stdio.h>
 
 #define JSERVER_VERSION 0x4200  /* minor version */
-#define _SERVER_VERSION "FreeWnn 1.1.0 pl21"
+#define _SERVER_VERSION "FreeWnn 1.1.0 pl22"
 
 #include "wnnerror.h"
 
@@ -75,9 +75,6 @@ typedef unsigned char UCHAR;
 # ifndef        SYSVR2
 #  define       SYSVR2
 # endif
-# ifndef        TERMINFO
-#  define       TERMINFO
-# endif
 #else /* if defined(MACH) || defined(uniosb) */
 # ifndef        BSD42
 #  define       BSD42
@@ -90,34 +87,22 @@ typedef unsigned char UCHAR;
 #    define     BSD44
 #   endif
 #  endif /* defined(luna68k) */
-# ifndef        TERMCAP
-#  define       TERMCAP
-# endif
 #endif
 #else /* defined(luna) */
 #if defined(sun) && !defined(SVR4)
 # ifndef        BSD42
 #  define       BSD42
 # endif
-# ifndef        TERMCAP
-#  define       TERMCAP
-# endif
 #else /* sun else */
 #if defined(DGUX) || defined(linux)
 # ifndef        SYSVR2
 #  define       SYSVR2
 # endif
-# ifndef        TERMCAP
-#  define       TERMCAP
-# endif
 #else
-#if defined(SVR4) || defined(hpux)
+#if defined(SVR4) || defined(hpux) || defined(SYSV) || defined(USG)
 # ifndef        SYSVR2
 #  define       SYSVR2
 # endif
-# ifndef        TERMINFO
-#  define       TERMINFO
-# endif
 # ifdef sun
 #  define SOLARIS
 # endif
@@ -128,22 +113,19 @@ typedef unsigned char UCHAR;
 # ifndef        BSD42
 #  define       BSD42
 # endif
-# ifndef        TERMCAP
-#  define       TERMCAP
-# endif
-#endif /* defined(SVR4) || defined(hpux) */
+#endif /* defined(SVR4) || defined(hpux) || defined(SYSV) || defined(USG) */
 #endif /* DGUX */
 #endif /* sun */
 #endif /* luna */
 
-#if defined(SVR4) || defined(hpux)
+#if defined(SVR4) || defined(hpux) || defined(SYSV) || defined(USG)
 #ifndef F_OK
 #define F_OK    0
 #endif
 #ifndef R_OK
 #define R_OK    4
 #endif
-#endif
+#endif /* defined(SVR4) || defined(hpux) || defined(SYSV) || defined(USG) */
 
 #define MAXBUNSETSU     80
 #define LIMITBUNSETSU   400
