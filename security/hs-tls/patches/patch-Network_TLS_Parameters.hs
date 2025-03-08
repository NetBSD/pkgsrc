$NetBSD: patch-Network_TLS_Parameters.hs,v 1.1 2025/03/08 05:10:18 pho Exp $

Don't require RFC 7627 Extended Master Secret by default. This patch is
very regrettable. We really shouldn't do this. But, let's face the
reality. Not all TLS 1.2 servers out there support RFC 7627. lang/elm
especially suffers from this, because its package server doesn't support
this extension.

--- Network/TLS/Parameters.hs.orig	2025-03-08 04:58:15.060237703 +0000
+++ Network/TLS/Parameters.hs
@@ -364,7 +364,7 @@ defaultSupported =
         , supportedHashSignatures = Struct.supportedSignatureSchemes
         , supportedSecureRenegotiation = True
         , supportedClientInitiatedRenegotiation = False
-        , supportedExtendedMainSecret = RequireEMS
+        , supportedExtendedMainSecret = AllowEMS
         , supportedSession = True
         , supportedFallbackScsv = True
         , supportedEmptyPacket = True
