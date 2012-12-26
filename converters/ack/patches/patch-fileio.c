$NetBSD: patch-fileio.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- use standard headers
- declare own functions
- avoid implicit int
- declare void functions void
- don't truncate time_t
- use size_t for sizes where easy and appropriate
- use a bit of const
- remove wrong usage of utime(3) and use utimes(3)

--- fileio.c.orig	1994-06-12 05:31:00.000000000 +0000
+++ fileio.c
@@ -5,14 +5,18 @@
 /* v1.10  1994 03/19	Ogasawara Hiroyuki		*/
 
 #include	<stdio.h>
+#include	<utime.h>
+
+#include	"kanjicode.h"
+#include	"misc.h"
 
 #define	EMPTY		0
 #define	STACKSIZE	256
 #define	PRESIZE		(1024*16)
 
 static int	cstack[STACKSIZE],
-		*cstackptr= cstack,
-		presize= 0;
+		*cstackptr= cstack;
+static size_t	presize= 0;
 unsigned char	prebuf[PRESIZE],
 		*preptr= prebuf;
 
@@ -36,7 +40,7 @@ unsigned int	code;
 }
 
 int
-getcode()
+getcode(void)
 {
 	if( cstackptr > cstack )
 		return	*--cstackptr;
@@ -48,7 +52,7 @@ getcode()
 }
 
 void
-ungetcode( code )
+ungetcode( int code )
 {
 	*cstackptr++= code;
 }
@@ -62,31 +66,33 @@ void	*cp;
 }
 
 #if HUMAN
-isdir( name )
-char	*name;
+int
+isdir( const char *name )
 {
 	return	CHMOD( name, -1 ) & 0x10;
 }
 #else
 #include	<sys/types.h>
 #include	<sys/stat.h>
-filedate( fn )
+time_t
+filedate( int fn )
 {
 	struct stat	st;
 	fstat( fn, &st );
 	return	st.st_mtime;
 }
 
-filesetdate( name, set )
-char	*name;
+void
+filesetdate( const char *name, time_t set )
 {
-	time_t	tim[2];
-	tim[0]= tim[1]= set;
-	utime( name, tim );
+	struct timeval	tim[2];
+	tim[0].tv_sec = tim[1].tv_sec = set;
+	tim[0].tv_usec = tim[1].tv_usec = 0;
+	utimes( name, tim );
 }
 
-isdir( name )
-char	*name;
+int
+isdir( const char *name )
 {
 	struct stat	st;
 	stat( name, &st );
