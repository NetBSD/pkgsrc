$NetBSD: patch-tme_common.h,v 1.1 2015/09/13 15:08:09 joerg Exp $

--- tme/common.h.orig	2015-09-03 14:41:12.000000000 +0000
+++ tme/common.h
@@ -169,7 +169,7 @@ _TME_RCSID("$Id: common.h,v 1.16 2010/02
 #define TME_FIELD_DEPOSIT8(v, s, l, x) _TME_FIELD_DEPOSIT(tme_uint8_t, v, s, l, x)
 #define TME_FIELD_DEPOSIT16(v, s, l, x) _TME_FIELD_DEPOSIT(tme_uint16_t, v, s, l, x)
 #define TME_FIELD_DEPOSIT32(v, s, l, x) _TME_FIELD_DEPOSIT(tme_uint32_t, v, s, l, x)
-#define _TME_FIELD_MASK_FACTOR(m) (((m) | ((m) << 1)) ^ ((m) << 1))
+#define _TME_FIELD_MASK_FACTOR(m) (((m) | ((m) * 2)) ^ ((m) * 2))
 #define TME_FIELD_MASK_EXTRACTU(v, m) (((v) & (m)) / _TME_FIELD_MASK_FACTOR(m))
 #define TME_FIELD_MASK_DEPOSITU(v, m, x) ((v) = (((v) & ~(m)) | (((x) * _TME_FIELD_MASK_FACTOR(m)) & (m))))
 #define _TME_FIELD_MASK_MSBIT(m) (((m) | ((m) >> 1)) ^ ((m) >> 1))
