$NetBSD: patch-tracejit_Writer.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- tracejit/Writer.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ tracejit/Writer.cpp
@@ -246,7 +246,9 @@ couldBeObjectOrString(LIns *ins)
         // ins = andq ins_oprnd1, ins_oprnd2
         ret = true;
 #endif
-    } else if (ins->isop(LIR_addp) &&
+    }
+#ifdef JS_HAS_STATIC_STRINGS
+	else if (ins->isop(LIR_addp) &&
                ((ins->oprnd1()->isImmP() &&
                  (void *)ins->oprnd1()->immP() == JSString::unitStringTable) ||
                 (ins->oprnd2()->isImmP() &&
@@ -258,6 +260,7 @@ couldBeObjectOrString(LIns *ins)
         // ins = addp JSString::unitStringTable, ...
         ret = true;
     }
+#endif
 
     return ret;
 }
