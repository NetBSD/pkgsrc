$NetBSD: patch-Modules_pyexpat.c,v 1.1 2012/05/05 22:16:15 joerg Exp $

--- Modules/pyexpat.c.orig	2012-05-05 17:15:36.000000000 +0000
+++ Modules/pyexpat.c
@@ -1355,8 +1355,13 @@ newxmlparseobject(char *encoding, char *
     else {
         self->itself = XML_ParserCreate(encoding);
     }
+#if ((XML_MAJOR_VERSION >= 2) && (XML_MINOR_VERSION >= 1)) || defined(XML_HAS_SET_HASH_SALT)
+    /* This feature was added upstream in libexpat 2.1.0.  Our expat copy
+     * has a backport of this feature where we also define XML_HAS_SET_HASH_SALT
+     * to indicate that we can still use it. */
     XML_SetHashSalt(self->itself,
                     (unsigned long)_Py_HashSecret.prefix);
+#endif
     self->intern = intern;
     Py_XINCREF(self->intern);
 #ifdef Py_TPFLAGS_HAVE_GC
