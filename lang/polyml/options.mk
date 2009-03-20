# $NetBSD: options.mk,v 1.1.1.1 2009/03/20 21:12:51 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.polyml
PKG_SUPPORTED_OPTIONS=	motif x11
PKG_SUGGESTED_OPTIONS=	motif x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
.endif
