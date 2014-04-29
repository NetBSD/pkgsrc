$NetBSD: patch-src_modules_rlm__pap_rlm__pap.c,v 1.1.2.2 2014/04/29 08:37:02 tron Exp $

Increase buffer size, and use output buffer size as limit for hex2bin.
Should fix CVE-2014-2015, patch from
https://github.com/FreeRADIUS/freeradius-server/commit/0d606cfc29a

--- src/modules/rlm_pap/rlm_pap.c.orig	2012-09-10 11:51:34.000000000 +0000
+++ src/modules/rlm_pap/rlm_pap.c
@@ -245,7 +245,7 @@ static int base64_decode (const char *sr
 static void normify(REQUEST *request, VALUE_PAIR *vp, size_t min_length)
 {
 	size_t decoded;
-	uint8_t buffer[64];
+	uint8_t buffer[256];
 
 	if (min_length >= sizeof(buffer)) return; /* paranoia */
 
@@ -253,7 +253,7 @@ static void normify(REQUEST *request, VA
 	 *	Hex encoding.
 	 */
 	if (vp->length >= (2 * min_length)) {
-		decoded = fr_hex2bin(vp->vp_strvalue, buffer, vp->length >> 1);
+		decoded = fr_hex2bin(vp->vp_strvalue, buffer, sizeof(buffer));
 		if (decoded == (vp->length >> 1)) {
 			RDEBUG2("Normalizing %s from hex encoding", vp->name);
 			memcpy(vp->vp_octets, buffer, decoded);
