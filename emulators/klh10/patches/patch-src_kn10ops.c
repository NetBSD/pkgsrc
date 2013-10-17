$NetBSD: patch-src_kn10ops.c,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/kn10ops.c.orig	2001-11-10 13:29:09.000000000 +0000
+++ src/kn10ops.c
@@ -759,7 +759,7 @@ dw10_t op10ashc(register dw10_t d,
 **	must be done to the argument prior to the call!
 */
 static dw10_t
-x_ashc(register dw10_t d,
+x_ashc(/*register*/ dw10_t d,
        register int i)
 {
 #endif /* IFFLAGS */
@@ -3238,7 +3238,7 @@ static int qdivstep(qw10_t *aq,
 		    register dw10_t d,
 		    register int nmagbits)
 {
-    register qw10_t qw;
+    /*register*/ qw10_t qw;
     dw10_t quot;
     register int qbit;
 
