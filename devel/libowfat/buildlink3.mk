# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:21 joerg Exp $

BUILDLINK_TREE+=	libowfat

.if !defined(LIBOWFAT_BUILDLINK3_MK)
LIBOWFAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libowfat+=	libowfat>=0.26
BUILDLINK_PKGSRCDIR.libowfat?=		../../devel/libowfat
BUILDLINK_DEPMETHOD.libowfat?=		build
.endif # LIBOWFAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libowfat
