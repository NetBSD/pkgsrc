# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/15 18:59:38 gls Exp $

BUILDLINK_TREE+=	libraw

.if !defined(LIBRAW_BUILDLINK3_MK)
LIBRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.10.0
BUILDLINK_PKGSRCDIR.libraw?=	../../graphics/libraw
.endif	# LIBRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libraw
