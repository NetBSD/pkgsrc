# $NetBSD: options.mk,v 1.1.1.1 2012/06/02 07:19:33 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xnp2
PKG_SUPPORTED_OPTIONS=	xnp2-ia32
PKG_SUGGESTED_OPTIONS=	xnp2-ia32

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxnp2-ia32)
# Enable ia32 core instead of the default 80286 core
CONFIGURE_ARGS+=	--enable-ia32
.endif
