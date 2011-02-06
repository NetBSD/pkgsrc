$NetBSD: patch-src_sha.cpp,v 1.1.1.1 2011/02/06 19:46:48 schnoebe Exp $

# correct an SHA1 implementation error, only evident when the message
# block is exactly 56 bytes long.
#
# This has been fixed upstream in the dev branch.
#

--- src/sha.cpp.orig	2009-10-12 09:38:59.000000000 -0500
+++ src/sha.cpp
@@ -214,7 +214,7 @@ namespace gloox
   {
     Message_Block[Message_Block_Index++] = 0x80;
 
-    if( Message_Block_Index > 55 )
+    if( Message_Block_Index > 56 )
     {
       while( Message_Block_Index < 64 )
       {
