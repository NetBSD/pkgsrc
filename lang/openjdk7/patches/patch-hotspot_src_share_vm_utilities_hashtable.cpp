$NetBSD: patch-hotspot_src_share_vm_utilities_hashtable.cpp,v 1.1 2014/01/08 13:09:38 jperkin Exp $

Delete obsolete (and now harmful) SunOS code.

--- hotspot/src/share/vm/utilities/hashtable.cpp.orig	2014-01-01 05:50:08.000000000 +0000
+++ hotspot/src/share/vm/utilities/hashtable.cpp
@@ -318,9 +318,6 @@ template class Hashtable<constantPoolOop
 template class Hashtable<Symbol*, mtSymbol>;
 template class Hashtable<klassOop, mtClass>;
 template class Hashtable<oop, mtClass>;
-#ifdef SOLARIS
-template class Hashtable<oop, mtSymbol>;
-#endif
 template class Hashtable<oopDesc*, mtSymbol>;
 template class Hashtable<Symbol*, mtClass>;
 template class HashtableEntry<Symbol*, mtSymbol>;
