# $NetBSD: buildlink3.mk,v 1.5 2023/08/14 05:24:35 wiz Exp $
#

BUILDLINK_TREE+=	libsixel

.if !defined(LIBSIXEL_BUILDLINK3_MK)
LIBSIXEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsixel+=	libsixel>=1.7.0
BUILDLINK_ABI_DEPENDS.libsixel+=	libsixel>=1.8.6nb14
BUILDLINK_PKGSRCDIR.libsixel?=		../../graphics/libsixel
.endif	# LIBSIXEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsixel
