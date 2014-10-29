# $NetBSD: options.mk,v 1.1.1.1 2014/10/29 23:10:29 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liblbfgs
PKG_SUPPORTED_OPTIONS=	liblbfgs-sse2
PKG_SUGGESTED_OPTIONS=	liblbfgs-sse2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mliblbfgs-sse2)
CONFIGURE_ARGS+=	--enable-sse2
.endif
