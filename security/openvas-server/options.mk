# $NetBSD: options.mk,v 1.2 2019/11/04 21:12:56 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openvas-server

PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
USE_X11=		YES
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif
