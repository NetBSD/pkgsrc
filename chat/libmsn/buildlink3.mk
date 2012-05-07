# $NetBSD: buildlink3.mk,v 1.4 2012/05/07 01:53:16 dholland Exp $

BUILDLINK_TREE+=	libmsn

.if !defined(LIBMSN_BUILDLINK3_MK)
LIBMSN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmsn+=	libmsn>=4.0beta2
BUILDLINK_ABI_DEPENDS.libmsn+=	libmsn>=4.0beta2nb1
BUILDLINK_PKGSRCDIR.libmsn?=	../../chat/libmsn

.include "../../security/openssl/buildlink3.mk"
.endif # LIBMSN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmsn
