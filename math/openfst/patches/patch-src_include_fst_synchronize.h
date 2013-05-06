$NetBSD: patch-src_include_fst_synchronize.h,v 1.2 2013/05/06 14:52:54 joerg Exp $

--- src/include/fst/synchronize.h.orig	2009-03-21 03:35:34.000000000 +0000
+++ src/include/fst/synchronize.h
@@ -20,11 +20,21 @@
 #ifndef FST_LIB_SYNCHRONIZE_H__
 #define FST_LIB_SYNCHRONIZE_H__
 
-#include <algorithm>
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#include <unordered_set>
+using std::unordered_set;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
 #include <tr1/unordered_set>
 using std::tr1::unordered_set;
+#endif
+
+#include <algorithm>
 #include <string>
 #include <utility>
 #include <vector>
@@ -111,7 +121,7 @@ class SynchronizeFstImpl
         return kNoStateId;
       const String *empty = FindString(new String());
       StateId start = FindState(Element(fst_->Start(), empty, empty));
-      SetStart(start);
+      this->SetStart(start);
     }
     return CacheImpl<A>::Start();
   }
@@ -121,9 +131,9 @@ class SynchronizeFstImpl
       const Element &e = elements_[s];
       Weight w = e.state == kNoStateId ? Weight::One() : fst_->Final(e.state);
       if ((w != Weight::Zero()) && (e.istring)->empty() && (e.ostring)->empty())
-        SetFinal(s, w);
+        this->SetFinal(s, w);
       else
-        SetFinal(s, Weight::Zero());
+        this->SetFinal(s, Weight::Zero());
     }
     return CacheImpl<A>::Final(s);
   }
@@ -230,13 +240,13 @@ class SynchronizeFstImpl
           const String *istring = Cdr(e.istring, arc.ilabel);
           const String *ostring = Cdr(e.ostring, arc.olabel);
           StateId d = FindState(Element(arc.nextstate, istring, ostring));
-          AddArc(s, Arc(Car(e.istring, arc.ilabel),
+          this->AddArc(s, Arc(Car(e.istring, arc.ilabel),
                         Car(e.ostring, arc.olabel), arc.weight, d));
         } else {
           const String *istring = Concat(e.istring, arc.ilabel);
           const String *ostring = Concat(e.ostring, arc.olabel);
           StateId d = FindState(Element(arc.nextstate, istring, ostring));
-          AddArc(s, Arc(0 , 0, arc.weight, d));
+          this->AddArc(s, Arc(0 , 0, arc.weight, d));
         }
       }
 
@@ -246,9 +256,9 @@ class SynchronizeFstImpl
       const String *istring = Cdr(e.istring);
       const String *ostring = Cdr(e.ostring);
       StateId d = FindState(Element(kNoStateId, istring, ostring));
-      AddArc(s, Arc(Car(e.istring), Car(e.ostring), w, d));
+      this->AddArc(s, Arc(Car(e.istring), Car(e.ostring), w, d));
     }
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
