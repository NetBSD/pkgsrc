# $NetBSD: buildlink3.mk,v 1.1 2014/07/13 10:10:56 obache Exp $
#

BUILDLINK_TREE+=	libsixel

.if !defined(LIBSIXEL_BUILDLINK3_MK)
LIBSIXEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsixel+=	libsixel>=0.11.0
BUILDLINK_PKGSRCDIR.libsixel?=	../../graphics/libsixel
.endif	# LIBSIXEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsixel
