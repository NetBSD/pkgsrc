$NetBSD: patch-src_extension_internal_pdfinput_poppler-utils.cpp,v 1.1 2026/06/24 21:57:17 wiz Exp $

poppler 26.6 support.
https://gitlab.com/inkscape/inkscape/-/merge_requests/7919
https://gitlab.com/inkscape/inkscape/-/work_items/6210

--- src/extension/internal/pdfinput/poppler-utils.cpp.orig	2026-04-23 22:59:59.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-utils.cpp
@@ -195,15 +195,17 @@ void InkFontDict::hashFontObject1(const Object *obj, F
                 hashFontObject1(&obj2, h);
             }
             break;
-        case objDict:
-            h->hash('d');
-            n = obj->dictGetLength();
-            h->hash((char *)&n, sizeof(int));
-            for (i = 0; i < n; ++i) {
-                p = obj->dictGetKey(i);
-                h->hash(p, (int)strlen(p));
-                const Object &obj2 = obj->dictGetValNF(i);
-                hashFontObject1(&obj2, h);
+        case objDict: {
+                h->hash('d');
+                auto objdict = obj->getDict();
+                n = objdict->getLength();
+                h->hash((char *)&n, sizeof(int));
+                for (i = 0; i < n; ++i) {
+                    auto p = std::string(objdict->getKey(i));
+                    h->hash(p.c_str(), p.length());
+                    const Object &obj2 = objdict->getValNF(i);
+                    hashFontObject1(&obj2, h);
+                }
             }
             break;
         case objStream:
