$NetBSD: patch-src_ifd_process.c,v 1.1 2026/02/03 08:39:15 wiz Exp $

Fix build with gcc 14.
https://github.com/OpenSC/openct/pull/12

--- src/ifd/process.c.orig	2009-02-01 08:26:40.000000000 +0000
+++ src/ifd/process.c
@@ -366,7 +366,7 @@ static int do_verify(ifd_reader_t * reader, int unit, 
 	ct_tlv_get_int(args, CT_TAG_TIMEOUT, &timeout);
 	if (ct_tlv_get_string(args, CT_TAG_MESSAGE, msgbuf, sizeof(msgbuf)) > 0)
 		message = msgbuf;
-	if (!ct_tlv_get_opaque(args, CT_TAG_PIN_DATA, &data, &data_len))
+	if (!ct_tlv_get_opaque(args, CT_TAG_PIN_DATA, &data, (size_t *)&data_len))
 		return IFD_ERROR_MISSING_ARG;
 
 	rc = ifd_card_perform_verify(reader, unit, timeout, message,
@@ -458,7 +458,7 @@ static int do_memory_write(ifd_reader_t * reader, int 
 		return IFD_ERROR_INVALID_SLOT;
 
 	if (ct_tlv_get_int(args, CT_TAG_ADDRESS, &address) == 0
-	    || !ct_tlv_get_opaque(args, CT_TAG_DATA, &data, &data_len))
+	    || !ct_tlv_get_opaque(args, CT_TAG_DATA, &data, (size_t *)&data_len))
 		return IFD_ERROR_MISSING_ARG;
 
 	rc = ifd_card_write_memory(reader, unit, address, data, data_len);
