# $NetBSD: buildlink3.mk,v 1.7 2016/03/05 11:27:41 jperkin Exp $

BUILDLINK_TREE+=	libmsn

.if !defined(LIBMSN_BUILDLINK3_MK)
LIBMSN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmsn+=	libmsn>=4.0beta2
BUILDLINK_ABI_DEPENDS.libmsn+=	libmsn>=4.2.1nb3
BUILDLINK_PKGSRCDIR.libmsn?=	../../chat/libmsn

.include "../../security/openssl/buildlink3.mk"
.endif # LIBMSN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmsn
