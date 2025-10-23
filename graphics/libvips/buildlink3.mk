# $NetBSD: buildlink3.mk,v 1.3 2025/10/23 20:37:39 wiz Exp $

BUILDLINK_TREE+=	libvips

.if !defined(LIBVIPS_BUILDLINK3_MK)
LIBVIPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvips+=	libvips>=8.16.0
BUILDLINK_ABI_DEPENDS.libvips?=	libvips>=8.17.1nb4
BUILDLINK_PKGSRCDIR.libvips?=	../../graphics/libvips

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBVIPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvips
