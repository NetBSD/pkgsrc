$NetBSD: patch-mozilla_js_xpconnect_src_XPCWrappedNative.cpp,v 1.1 2021/11/18 15:33:16 nia Exp $

Avoid error when compiling with gcc 9:
XPCWrappedNative.cpp:2221:41: error: '%s' directive argument is null [-Werror=format-overflow=]
 2221 |                 name = JS_sprintf_append(name, fmt,
      |                        ~~~~~~~~~~~~~~~~~^~~~~~~~~~~
 2222 |                                          array[i]->GetNameString());
      |                                          ~~~~~~~~~~~~~~~~~~~~~~~~~~

--- mozilla/js/xpconnect/src/XPCWrappedNative.cpp.orig	2018-07-09 19:54:43.000000000 +0000
+++ mozilla/js/xpconnect/src/XPCWrappedNative.cpp
@@ -2218,8 +2218,10 @@ XPCWrappedNative::ToString(XPCWrappedNat
                 const char* fmt = (i == 0) ?
                                     "(%s" : (i == count-1) ?
                                         ", %s)" : ", %s";
-                name = JS_sprintf_append(name, fmt,
-                                         array[i]->GetNameString());
+		const char *s = array[i]->GetNameString();
+		if (s == NULL)
+			s = "-";
+                name = JS_sprintf_append(name, fmt, s);
             }
         }
     }
