# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:01 joerg Exp $

BUILDLINK_TREE+=	libmsn

.if !defined(LIBMSN_BUILDLINK3_MK)
LIBMSN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmsn+=	libmsn>=4.0beta2
BUILDLINK_PKGSRCDIR.libmsn?=	../../chat/libmsn

.include "../../security/openssl/buildlink3.mk"
.endif # LIBMSN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmsn
