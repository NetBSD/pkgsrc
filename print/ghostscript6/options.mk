# $NetBSD: options.mk,v 1.2 2007/02/15 23:01:43 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
XLIBS=			Xt SM ICE Xext X11
GS_DISPLAY_DEVICE=	x11.dev
MAKEFRAGS+=		${FILESDIR}/devs.x11
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
XLIBS?=			# empty
GS_DISPLAY_DEVICE?=	# empty
.endif
