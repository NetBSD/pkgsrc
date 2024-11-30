$NetBSD: patch-src_libcmis_xml-utils.cxx,v 1.3 2024/11/30 20:31:31 wiz Exp $

Boost 1.86 compat
https://github.com/tdf/libcmis/commit/dfcb642a491f7ec2ae52e3e83d31bb6cdf3670c2

--- src/libcmis/xml-utils.cxx.orig	2023-10-09 12:06:53.000000000 +0000
+++ src/libcmis/xml-utils.cxx
@@ -535,16 +535,22 @@ namespace libcmis
         boost::uuids::detail::sha1 sha1;
         sha1.process_bytes( str.c_str(), str.size() );
 
-        unsigned int digest[5];
+        // on boost <  1.86.0, digest_type is typedef'd as unsigned int[5]
+        // on boost >= 1.86.0, digest_type is typedef'd as unsigned char[20]
+        boost::uuids::detail::sha1::digest_type digest;
         sha1.get_digest( digest );
 
+        // by using a pointer to unsigned char, we can read the
+        // object representation of either typedef.
+        const unsigned char* ptr = reinterpret_cast<const unsigned char*>( digest );
+
         stringstream out;
-        // Setup writing mode. Every number must produce eight
+        // Setup writing mode. Every number must produce two
         // hexadecimal digits, including possible leading 0s, or we get
         // less than 40 digits as result.
         out << hex << setfill('0') << right;
-        for ( int i = 0; i < 5; ++i )
-            out << setw(8) << digest[i];
+        for ( int i = 0; i < sizeof( digest ); ++ptr, ++i )
+            out << setw(2) << static_cast<int>( *ptr );
         return out.str();
     }
 
