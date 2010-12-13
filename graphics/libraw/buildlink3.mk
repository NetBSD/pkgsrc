# $NetBSD: buildlink3.mk,v 1.2 2010/12/13 20:32:30 gls Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.12.0
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
