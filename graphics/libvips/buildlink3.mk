# $NetBSD: buildlink3.mk,v 1.1 2025/08/20 16:47:24 schmonz Exp $

BUILDLINK_TREE+=	libvips

.if !defined(LIBVIPS_BUILDLINK3_MK)
LIBVIPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvips+=	libvips>=8.16.0
BUILDLINK_PKGSRCDIR.libvips?=	../../graphics/libvips

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBVIPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvips
