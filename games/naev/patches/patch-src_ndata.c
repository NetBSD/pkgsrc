$NetBSD: patch-src_ndata.c,v 1.1 2019/10/01 12:25:37 nia Exp $

Support loading data from @DATADIR@ (set in the Makefile).

$NetBSD: patch-src_ndata.c,v 1.1 2019/10/01 12:25:37 nia Exp $

--- src/ndata.c.orig	2015-03-17 16:29:43.000000000 +0000
+++ src/ndata.c
@@ -17,7 +17,7 @@
  *  2) conf.lua option
  * -- DONE AS NEEDED --
  *  3) Current dir laid out (does not work well when iterating through directories)
- *  4) ndata-$VERSION
+ *  4) @DATADIR@/ndata-$VERSION
  *  5) Makefile version
  *  6) ./ndata*
  *  7) dirname(argv[0])/ndata* (binary path)
@@ -408,9 +408,9 @@ static int ndata_openFile (void)
 
       /* Check ndata with version appended. */
 #if VREV < 0
-      nsnprintf ( pathname, PATH_MAX, "%s-%d.%d.0-beta%d", NDATA_FILENAME, VMAJOR, VMINOR, ABS ( VREV ) );
+      nsnprintf ( pathname, PATH_MAX, "@DATADIR@/%s-%d.%d.0-beta%d", NDATA_FILENAME, VMAJOR, VMINOR, ABS ( VREV ) );
 #else /* VREV < 0 */
-      nsnprintf ( pathname, PATH_MAX, "%s-%d.%d.%d", NDATA_FILENAME, VMAJOR, VMINOR, VREV );
+      nsnprintf ( pathname, PATH_MAX, "@DATADIR@/%s-%d.%d.%d", NDATA_FILENAME, VMAJOR, VMINOR, VREV );
 #endif /* VREV < 0 */
 
       if (ndata_isndata(pathname)) {
