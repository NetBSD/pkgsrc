# $NetBSD: buildlink3.mk,v 1.1 2012/08/04 14:31:27 drochner Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.12.0
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw013

.include "../../graphics/lcms/buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
