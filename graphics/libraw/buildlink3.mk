# $NetBSD: buildlink3.mk,v 1.3 2010/12/14 07:43:45 gls Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.12.0
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw

.include "../../graphics/lcms/buildlink3.mk"
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
