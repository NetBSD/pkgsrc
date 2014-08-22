# $NetBSD: buildlink3.mk,v 1.2 2014/08/22 10:25:09 obache Exp $
#

BUILDLINK_TREE+=	libsixel

.if !defined(LIBSIXEL_BUILDLINK3_MK)
LIBSIXEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsixel+=	libsixel>=0.11.0
BUILDLINK_ABI_DEPENDS.libsixel+=	libsixel>=1.0.0
BUILDLINK_PKGSRCDIR.libsixel?=	../../graphics/libsixel
.endif	# LIBSIXEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsixel
