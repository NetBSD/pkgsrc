# $NetBSD: buildlink3.mk,v 1.4 2012/08/04 14:36:42 drochner Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.12.0
BUILDLINK_ABI_DEPENDS.libraw+=	libraw>=0.14.6
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../graphics/lcms/buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
