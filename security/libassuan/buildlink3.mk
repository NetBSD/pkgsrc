# $NetBSD: buildlink3.mk,v 1.11 2012/05/07 01:53:56 dholland Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=1.0.0
BUILDLINK_API_DEPENDS.libassuan+=	libassuan<2.0.0
BUILDLINK_ABI_DEPENDS.libassuan+=	libassuan>=1.0.5nb1
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
