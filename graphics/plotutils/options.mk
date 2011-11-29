# $NetBSD: options.mk,v 1.2 2011/11/29 17:55:07 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.plotutils
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
