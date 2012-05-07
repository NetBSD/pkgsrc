# $NetBSD: buildlink3.mk,v 1.13 2012/05/07 01:53:17 dholland Exp $

BUILDLINK_TREE+=	libotr

.if !defined(LIBOTR_BUILDLINK3_MK)
LIBOTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libotr+=	libotr>=3.0.0
BUILDLINK_ABI_DEPENDS.libotr+=	libotr>=3.2.0nb1
BUILDLINK_PKGSRCDIR.libotr?=	../../chat/libotr

.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBOTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libotr
