$NetBSD: patch-src_tinygettext_TinyGetText.cpp,v 1.1 2012/12/24 06:22:14 dholland Exp $

Remove any getchar macro before declaring a getchar member function.
Required for building on DragonFly.

--- src/tinygettext/TinyGetText.cpp~	2009-01-25 20:20:41.000000000 +0000
+++ src/tinygettext/TinyGetText.cpp
@@ -680,6 +680,7 @@ public:
       }
   }
 
+#undef getchar
   inline int getchar(std::istream& in)
   {
     int c = in.get();
