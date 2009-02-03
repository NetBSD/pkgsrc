# $NetBSD: buildlink3.mk,v 1.2 2009/02/03 06:21:40 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GEGL_BUILDLINK3_MK:=	${GEGL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gegl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngegl}
BUILDLINK_PACKAGES+=	gegl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gegl

.if ${GEGL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.0.20
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl
.endif	# GEGL_BUILDLINK3_MK

pkgbase := gegl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gegl:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../graphics/babl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
