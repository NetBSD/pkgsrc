# $NetBSD: buildlink3.mk,v 1.3 2006/10/23 12:11:35 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GRAPHICSMAGICK_BUILDLINK3_MK:=	${GRAPHICSMAGICK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	GraphicsMagick
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGraphicsMagick}
BUILDLINK_PACKAGES+=	GraphicsMagick
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}GraphicsMagick

.if ${GRAPHICSMAGICK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.GraphicsMagick+=	GraphicsMagick>=1.1.7
BUILDLINK_PKGSRCDIR.GraphicsMagick?=	../../graphics/GraphicsMagick
.endif	# GRAPHICSMAGICK_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
