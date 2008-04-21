# $NetBSD: buildlink3.mk,v 1.27 2008/04/21 11:29:33 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CAIRO_BUILDLINK3_MK:=	${CAIRO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	cairo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncairo}
BUILDLINK_PACKAGES+=	cairo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cairo

.if ${CAIRO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.4
BUILDLINK_ABI_DEPENDS.cairo?=	cairo>=1.0.4nb1
BUILDLINK_PKGSRCDIR.cairo?=	../../graphics/cairo

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.endif	# CAIRO_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := cairo
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11)
.include "../../x11/libXrender/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
