# $NetBSD: buildlink3.mk,v 1.6 2023/04/13 14:13:56 wiz Exp $

BUILDLINK_TREE+=	libpaper

.if !defined(LIBPAPER_BUILDLINK3_MK)
LIBPAPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpaper+=	libpaper>=1.1.22
BUILDLINK_ABI_DEPENDS.libpaper?=		libpaper>=2.1.0
BUILDLINK_PKGSRCDIR.libpaper?=		../../print/libpaper
.endif # LIBPAPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpaper
