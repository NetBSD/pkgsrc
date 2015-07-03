$NetBSD: patch-hotspot_src_share_vm_utilities_hashtable.cpp,v 1.1 2015/07/03 20:40:59 fhajny Exp $

Delete obsolete (and now harmful) SunOS code.

--- hotspot/src/share/vm/utilities/hashtable.cpp.orig	2015-06-10 10:31:47.000000000 +0000
+++ hotspot/src/share/vm/utilities/hashtable.cpp
@@ -364,7 +364,7 @@ template class RehashableHashtable<oopDe
 template class Hashtable<Symbol*, mtSymbol>;
 template class Hashtable<Klass*, mtClass>;
 template class Hashtable<oop, mtClass>;
-#if defined(SOLARIS) || defined(CHECK_UNHANDLED_OOPS)
+#if defined(CHECK_UNHANDLED_OOPS)
 template class Hashtable<oop, mtSymbol>;
 template class RehashableHashtable<oop, mtSymbol>;
 #endif // SOLARIS || CHECK_UNHANDLED_OOPS
