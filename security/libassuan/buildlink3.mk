# $NetBSD: buildlink3.mk,v 1.9 2010/07/17 12:07:10 wiz Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=1.0.0
BUILDLINK_API_DEPENDS.libassuan+=	libassuan<2.0.0
BUILDLINK_ABI_DEPENDS.libassuan?=	libassuan>=1.0.0
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
