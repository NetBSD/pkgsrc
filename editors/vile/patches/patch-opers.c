$NetBSD: patch-opers.c,v 1.1 2025/04/19 00:29:37 agc Exp $

Patch for later versions of vile (i.e.  post 2016) which mangle the
dNd and yNy "second" count to be unrecognised and ignored

--- opers.c	2016/07/16 01:12:30	1.1
+++ opers.c	2016/07/16 01:12:38
@@ -75,7 +75,7 @@
 	     * Otherwise (if we picked up a repeat count on the second try),
 	     * then that can apply to a motion.
 	     */
-	    if (thiskey == lastkey && (foo || !f)) {
+	    if (thiskey == lastkey) {
 		cfp = &f_godotplus;
 	    } else {
 		cfp = DefaultKeyBinding(c);
