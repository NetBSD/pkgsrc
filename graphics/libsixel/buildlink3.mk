# $NetBSD: buildlink3.mk,v 1.3 2016/08/21 11:17:44 ryoon Exp $
#

BUILDLINK_TREE+=	libsixel

.if !defined(LIBSIXEL_BUILDLINK3_MK)
LIBSIXEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsixel+=	libsixel>=1.7.0
BUILDLINK_ABI_DEPENDS.libsixel+=	libsixel>=1.7.0
BUILDLINK_PKGSRCDIR.libsixel?=	../../graphics/libsixel
.endif	# LIBSIXEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsixel
