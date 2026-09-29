# $NetBSD: buildlink3.mk,v 1.7 2026/09/29 06:05:49 wiz Exp $

BUILDLINK_TREE+=	libvips

.if !defined(LIBVIPS_BUILDLINK3_MK)
LIBVIPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvips+=	libvips>=8.16.0
BUILDLINK_ABI_DEPENDS.libvips?=	libvips>=8.17.2nb13
BUILDLINK_PKGSRCDIR.libvips?=	../../graphics/libvips

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBVIPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvips
