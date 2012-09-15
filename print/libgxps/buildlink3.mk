# $NetBSD: buildlink3.mk,v 1.3 2012/09/15 10:06:11 obache Exp $

BUILDLINK_TREE+=	libgxps

.if !defined(LIBGXPS_BUILDLINK3_MK)
LIBGXPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgxps+=	libgxps>=0.2.1
BUILDLINK_ABI_DEPENDS.libgxps?=	libgxps>=0.2.2nb3
BUILDLINK_PKGSRCDIR.libgxps?=	../../print/libgxps

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.endif	# LIBGXPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgxps
