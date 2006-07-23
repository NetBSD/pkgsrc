# $NetBSD: buildlink3.mk,v 1.22 2006/07/23 04:07:34 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CAIRO_BUILDLINK3_MK:=	${CAIRO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cairo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncairo}
BUILDLINK_PACKAGES+=	cairo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cairo

.if !empty(CAIRO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
BUILDLINK_ABI_DEPENDS.cairo?=	cairo>=1.0.4nb1
BUILDLINK_PKGSRCDIR.cairo?=	../../graphics/cairo

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.endif	# CAIRO_BUILDLINK3_MK

.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_BUILD_OPTIONS.cairo)
PKG_BUILD_OPTIONS.cairo!= \
	cd ${BUILDLINK_PKGSRCDIR.cairo} && \
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.cairo=${PKG_BUILD_OPTIONS.cairo:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.cairo

.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11)
.include "../../x11/Xrender/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
