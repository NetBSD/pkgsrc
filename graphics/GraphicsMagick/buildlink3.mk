# $NetBSD: buildlink3.mk,v 1.1 2006/07/20 17:30:09 minskim Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.GraphicsMagick?=	build

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

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../archivers/bzip2/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/jpeg/buildlink3.mk"
#.include "../../graphics/lcms/buildlink3.mk"
#.include "../../graphics/libexif/buildlink3.mk"
#.include "../../graphics/libwmf/buildlink3.mk"
#.include "../../graphics/jasper/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
