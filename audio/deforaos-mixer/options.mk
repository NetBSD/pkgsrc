# $NetBSD: options.mk,v 1.2 2022/04/15 21:16:50 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-mixer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_ARGS+=	-M embedded-debug
.endif
