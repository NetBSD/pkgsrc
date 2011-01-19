# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/19 23:30:12 jmmv Exp $

BUILDLINK_TREE+=	libdmapsharing

.if !defined(LIBDMAPSHARING_BUILDLINK3_MK)
LIBDMAPSHARING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdmapsharing+=	libdmapsharing>=2.1.9
BUILDLINK_PKGSRCDIR.libdmapsharing?=	../../net/libdmapsharing

.endif	# LIBDMAPSHARING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdmapsharing
