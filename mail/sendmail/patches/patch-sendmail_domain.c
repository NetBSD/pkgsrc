$NetBSD: patch-sendmail_domain.c,v 1.1 2020/04/24 14:33:08 manu Exp $

Add missing curly brackets that caused res_ninit() to be called
with non-zeroed state structure. In NetBSD, res_ninit() detects
the mistake and quickly calls res_ndestroy(), which will close file
descriptors based on the random data provided in the state structure.
The result at mine is sendmail going mute after the MAIL FROM
command.

--- sendmail/domain.c.orig
+++ sendmail/domain.c
@@ -802,17 +802,18 @@
 
 	if (tTd(8, 2))
 		sm_dprintf("dns_getcanonname(%s, trymx=%d)\n", host, trymx);
 
-	if ((sm_res.options & RES_INIT) == 0)
+	if ((sm_res.options & RES_INIT) == 0) {
 # if NAMED_RESN
 		memset(&sm_res, 0, sizeof(sm_res));
 		if (res_ninit(&sm_res) == -1) {
 # else
 		if (res_init() == -1) {
 # endif
 			*statp = EX_UNAVAILABLE;
 			return false;
+		}
 	}
 
 	*statp = EX_OK;
 
