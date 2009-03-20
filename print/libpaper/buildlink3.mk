# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:15 joerg Exp $

BUILDLINK_TREE+=	libpaper

.if !defined(LIBPAPER_BUILDLINK3_MK)
LIBPAPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpaper+=	libpaper>=1.1.22
BUILDLINK_PKGSRCDIR.libpaper?=	../../print/libpaper
.endif # LIBPAPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpaper
