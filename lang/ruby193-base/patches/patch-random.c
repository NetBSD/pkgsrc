$NetBSD: patch-random.c,v 1.1.2.2 2012/11/26 23:46:36 tron Exp $

Fix build on SunOS by making sure endianness is known.
http://bugs.ruby-lang.org/projects/ruby-193/repository/revisions/37653

--- random.c.orig	2012-11-09 15:38:38.000000000 +0000
+++ random.c
@@ -1261,6 +1261,19 @@ random_s_rand(int argc, VALUE *argv, VAL
 
 #define SIP_HASH_STREAMING 0
 #define sip_hash24 ruby_sip_hash24
+#if !defined _WIN32 && !defined BYTE_ORDER
+# ifdef WORDS_BIGENDIAN
+#   define BYTE_ORDER BIG_ENDIAN
+# else
+#   define BYTE_ORDER LITTLE_ENDIAN
+# endif
+# ifndef LITTLE_ENDIAN
+#   define LITTLE_ENDIAN 1234
+# endif
+# ifndef BIG_ENDIAN
+#   define BIG_ENDIAN    4321
+# endif
+#endif
 #include "siphash.c"
 
 static st_index_t hashseed;
