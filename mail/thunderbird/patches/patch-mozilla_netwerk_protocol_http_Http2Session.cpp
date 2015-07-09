$NetBSD: patch-mozilla_netwerk_protocol_http_Http2Session.cpp,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/netwerk/protocol/http/Http2Session.cpp.orig	2015-06-08 17:49:29.000000000 +0000
+++ mozilla/netwerk/protocol/http/Http2Session.cpp
@@ -32,7 +32,6 @@
 #include "nsStandardURL.h"
 #include "nsURLHelper.h"
 #include "prprf.h"
-#include "prnetdb.h"
 #include "sslt.h"
 
 #ifdef DEBUG
@@ -1385,7 +1384,7 @@ Http2Session::RecvPriority(Http2Session 
     return rv;
 
   uint32_t newPriorityDependency =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   bool exclusive = !!(newPriorityDependency & 0x80000000);
   newPriorityDependency &= 0x7fffffff;
   uint8_t newPriorityWeight = *(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4);
@@ -1416,7 +1415,7 @@ Http2Session::RecvRstStream(Http2Session
   }
 
   self->mDownstreamRstReason =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
 
   LOG3(("Http2Session::RecvRstStream %p RST_STREAM Reason Code %u ID %x\n",
         self, self->mDownstreamRstReason, self->mInputFrameID));
@@ -1477,8 +1476,8 @@ Http2Session::RecvSettings(Http2Session 
     uint8_t *setting = reinterpret_cast<uint8_t *>
       (self->mInputFrameBuffer.get()) + kFrameHeaderBytes + index * 6;
 
-    uint16_t id = PR_ntohs(*reinterpret_cast<uint16_t *>(setting));
-    uint32_t value = PR_ntohl(*reinterpret_cast<uint32_t *>(setting + 2));
+    uint16_t id = NS_decodeN16(setting);
+    uint32_t value = NS_decodeN32(setting + 2);
     LOG3(("Settings ID %u, Value %u", id, value));
 
     switch (id)
@@ -1565,7 +1564,7 @@ Http2Session::RecvPushPromise(Http2Sessi
     }
     promiseLen = 4;
     promisedID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes));
+      NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes);
     promisedID &= 0x7fffffff;
   }
 
@@ -1828,11 +1827,11 @@ Http2Session::RecvGoAway(Http2Session *s
 
   self->mShouldGoAway = true;
   self->mGoAwayID =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   self->mGoAwayID &= 0x7fffffff;
   self->mCleanShutdown = true;
   uint32_t statusCode =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4);
 
   // Find streams greater than the last-good ID and mark them for deletion
   // in the mGoAwayStreamsToRestart queue with the GoAwayEnumerator. The
@@ -1906,7 +1905,7 @@ Http2Session::RecvWindowUpdate(Http2Sess
   }
 
   uint32_t delta =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   delta &= 0x7fffffff;
 
   LOG3(("Http2Session::RecvWindowUpdate %p len=%d Stream 0x%X.\n",
@@ -2543,7 +2542,7 @@ Http2Session::WriteSegments(nsAHttpSegme
 
     // 3 bytes of length, 1 type byte, 1 flag byte, 1 unused bit, 31 bits of ID
     uint8_t totallyWastedByte = mInputFrameBuffer.get()[0];
-    mInputFrameDataSize = PR_ntohs(*reinterpret_cast<uint16_t *>(mInputFrameBuffer.get() + 1));
+    mInputFrameDataSize = NS_decodeN16(mInputFrameBuffer.get() + 1);
     if (totallyWastedByte || (mInputFrameDataSize > kMaxFrameData)) {
       LOG3(("Got frame too large 0x%02X%04X", totallyWastedByte, mInputFrameDataSize));
       RETURN_SESSION_ERROR(this, PROTOCOL_ERROR);
@@ -2551,7 +2550,7 @@ Http2Session::WriteSegments(nsAHttpSegme
     mInputFrameType = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes);
     mInputFrameFlags = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes);
     mInputFrameID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes));
+      NS_decodeN32(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes);
     mInputFrameID &= 0x7fffffff;
     mInputFrameDataRead = 0;
 
