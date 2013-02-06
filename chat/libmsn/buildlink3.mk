# $NetBSD: buildlink3.mk,v 1.5 2013/02/06 23:20:51 jperkin Exp $

BUILDLINK_TREE+=	libmsn

.if !defined(LIBMSN_BUILDLINK3_MK)
LIBMSN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmsn+=	libmsn>=4.0beta2
BUILDLINK_ABI_DEPENDS.libmsn+=	libmsn>=4.2.1nb1
BUILDLINK_PKGSRCDIR.libmsn?=	../../chat/libmsn

.include "../../security/openssl/buildlink3.mk"
.endif # LIBMSN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmsn
