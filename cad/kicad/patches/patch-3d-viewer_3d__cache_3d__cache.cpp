$NetBSD: patch-3d-viewer_3d__cache_3d__cache.cpp,v 1.1 2024/10/04 04:25:36 ryoon Exp $

Fix build with boost-1.86.0 with a patch from upstream
From: https://gitlab.com/kicad/code/kicad/-/commit/9779ee0fd3c8891d80b0a75edc1ce673d7a82b0a

--- 3d-viewer/3d_cache/3d_cache.cpp.orig	2024-10-02 20:53:48.006013235 +0000
+++ 3d-viewer/3d_cache/3d_cache.cpp
@@ -381,7 +381,10 @@ bool S3D_CACHE::getSHA1( const wxString&
 
     fclose( fp );
     unsigned int digest[5];
-    dblock.get_digest( digest );
+
+        static_assert( sizeof( digest ) == sizeof( boost::uuids::detail::sha1::digest_type& ),
+                       "SHA1 digest size mismatch" );
+        dblock.get_digest( reinterpret_cast<boost::uuids::detail::sha1::digest_type&>( digest ) );
 
     // ensure MSB order
     for( int i = 0; i < 5; ++i )
@@ -696,4 +699,4 @@ void S3D_CACHE::CleanCacheDir( int aNumD
             }
         }
     }
-}
\ No newline at end of file
+}
