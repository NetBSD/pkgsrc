$NetBSD: patch-lib_uri_rfc3986__parser.rb,v 1.1.2.2 2023/07/05 11:48:45 bsiegert Exp $

Fix for CVE-2023-36617 updating uri to 0.12.2.

--- lib/uri/rfc3986_parser.rb.orig	2023-03-30 10:53:51.000000000 +0000
+++ lib/uri/rfc3986_parser.rb
@@ -100,7 +100,7 @@ module URI
         QUERY: /\A(?:%\h\h|[!$&-.0-;=@-Z_a-z~\/?])*\z/,
         FRAGMENT: /\A(?:%\h\h|[!$&-.0-;=@-Z_a-z~\/?])*\z/,
         OPAQUE: /\A(?:[^\/].*)?\z/,
-        PORT: /\A[\x09\x0a\x0c\x0d ]*\d*[\x09\x0a\x0c\x0d ]*\z/,
+        PORT: /\A[\x09\x0a\x0c\x0d ]*+\d*[\x09\x0a\x0c\x0d ]*\z/,
       }
     end
 
