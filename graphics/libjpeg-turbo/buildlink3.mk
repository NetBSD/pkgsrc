# $NetBSD: buildlink3.mk,v 1.3 2026/07/06 17:27:14 adam Exp $

BUILDLINK_TREE+=	libjpeg-turbo

.if !defined(LIBJPEG_TURBO_BUILDLINK3_MK)
LIBJPEG_TURBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjpeg-turbo+=	libjpeg-turbo>=1.1.0
BUILDLINK_PKGSRCDIR.libjpeg-turbo?=	../../graphics/libjpeg-turbo

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBJPEG_TURBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjpeg-turbo
