# $NetBSD: buildlink3.mk,v 1.1 2015/07/04 05:21:49 ryoon Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.2.0
BUILDLINK_ABI_DEPENDS.libassuan+=	libassuan>=2.2.0
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan22

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
