$NetBSD: patch-common_utext.cpp,v 1.1.2.1 2017/04/25 17:54:53 bsiegert Exp $

Apply upstream changeset 39671
ticket:12888 UText, problems with handling of bad UTF-8.

--- common/utext.cpp.orig	2016-06-15 18:58:17.000000000 +0000
+++ common/utext.cpp
@@ -889,7 +889,7 @@ struct UTF8Buf {
                                                      //  Requires two extra slots,
                                                      //    one for a supplementary starting in the last normal position,
                                                      //    and one for an entry for the buffer limit position.
-    uint8_t   mapToUChars[UTF8_TEXT_CHUNK_SIZE*3+6]; // Map native offset from bufNativeStart to
+    uint8_t   mapToUChars[UTF8_TEXT_CHUNK_SIZE*6+6]; // Map native offset from bufNativeStart to
                                                      //   correspoding offset in filled part of buf.
     int32_t   align;
 };
@@ -1032,6 +1032,7 @@ utf8TextAccess(UText *ut, int64_t index,
             // Requested index is in this buffer.
             u8b = (UTF8Buf *)ut->p;   // the current buffer
             mapIndex = ix - u8b->toUCharsMapStart;
+            U_ASSERT(mapIndex < (int32_t)sizeof(UTF8Buf::mapToUChars));
             ut->chunkOffset = u8b->mapToUChars[mapIndex] - u8b->bufStartIdx;
             return TRUE;
 
@@ -1298,6 +1299,10 @@ fillReverse:
         // Can only do this if the incoming index is somewhere in the interior of the string.
         //   If index is at the end, there is no character there to look at.
         if (ix != ut->b) {
+            // Note: this function will only move the index back if it is on a trail byte
+            //       and there is a preceding lead byte and the sequence from the lead 
+            //       through this trail could be part of a valid UTF-8 sequence
+            //       Otherwise the index remains unchanged.
             U8_SET_CP_START(s8, 0, ix);
         }
 
@@ -1311,7 +1316,10 @@ fillReverse:
         UChar   *buf = u8b->buf;
         uint8_t *mapToNative = u8b->mapToNative;
         uint8_t *mapToUChars = u8b->mapToUChars;
-        int32_t  toUCharsMapStart = ix - (UTF8_TEXT_CHUNK_SIZE*3 + 1);
+        int32_t  toUCharsMapStart = ix - sizeof(UTF8Buf::mapToUChars) + 1;
+        // Note that toUCharsMapStart can be negative. Happens when the remaining
+        // text from current position to the beginning is less than the buffer size.
+        // + 1 because mapToUChars must have a slot at the end for the bufNativeLimit entry
         int32_t  destIx = UTF8_TEXT_CHUNK_SIZE+2;   // Start in the overflow region
                                                     //   at end of buffer to leave room
                                                     //   for a surrogate pair at the
@@ -1338,6 +1346,7 @@ fillReverse:
             if (c<0x80) {
                 // Special case ASCII range for speed.
                 buf[destIx] = (UChar)c;
+                U_ASSERT(toUCharsMapStart <= srcIx);
                 mapToUChars[srcIx - toUCharsMapStart] = (uint8_t)destIx;
                 mapToNative[destIx] = (uint8_t)(srcIx - toUCharsMapStart);
             } else {
@@ -1367,6 +1376,7 @@ fillReverse:
                 do {
                     mapToUChars[sIx-- - toUCharsMapStart] = (uint8_t)destIx;
                 } while (sIx >= srcIx);
+                U_ASSERT(toUCharsMapStart <= (srcIx+1));
 
                 // Set native indexing limit to be the current position.
                 //   We are processing a non-ascii, non-native-indexing char now;
@@ -1541,6 +1551,7 @@ utf8TextMapIndexToUTF16(const UText *ut,
     U_ASSERT(index>=ut->chunkNativeStart+ut->nativeIndexingLimit);
     U_ASSERT(index<=ut->chunkNativeLimit);
     int32_t mapIndex = index - u8b->toUCharsMapStart;
+    U_ASSERT(mapIndex < (int32_t)sizeof(UTF8Buf::mapToUChars));
     int32_t offset = u8b->mapToUChars[mapIndex] - u8b->bufStartIdx;
     U_ASSERT(offset>=0 && offset<=ut->chunkLength);
     return offset;
