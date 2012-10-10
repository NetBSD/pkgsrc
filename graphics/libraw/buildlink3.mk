# $NetBSD: buildlink3.mk,v 1.5 2012/10/10 13:06:14 drochner Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.12.0
BUILDLINK_ABI_DEPENDS.libraw+=	libraw>=0.14.6
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../graphics/lcms2/buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
