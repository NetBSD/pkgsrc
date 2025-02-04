# $NetBSD: buildlink3.mk,v 1.3 2025/02/04 11:22:48 wiz Exp $

BUILDLINK_TREE+=	libjxl

.if !defined(LIBJXL_BUILDLINK3_MK)
LIBJXL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjxl+=	libjxl>=0.8.2
BUILDLINK_PKGSRCDIR.libjxl?=	../../graphics/libjxl

.include "../../archivers/brotli/buildlink3.mk"
.include "../../graphics/libhighway/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.endif	# LIBJXL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjxl
