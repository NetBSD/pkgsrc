# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:18 joerg Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=1.0.0
BUILDLINK_ABI_DEPENDS.libassuan?=	libassuan>=1.0.0
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
