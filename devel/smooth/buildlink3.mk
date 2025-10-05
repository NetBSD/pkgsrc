# $NetBSD: buildlink3.mk,v 1.3 2025/10/05 19:25:51 js Exp $

BUILDLINK_TREE+=	smooth

.if !defined(SMOOTH_BUILDLINK3_MK)
SMOOTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smooth+=	smooth>=0.9.10
BUILDLINK_ABI_DEPENDS.smooth?=	smooth>=0.9.10nb2
BUILDLINK_PKGSRCDIR.smooth?=	../../devel/smooth

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../sysutils/libcpuid/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# SMOOTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-smooth
