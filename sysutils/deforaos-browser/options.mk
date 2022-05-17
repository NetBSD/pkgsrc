# $NetBSD: options.mk,v 1.3 2022/05/17 17:44:27 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-browser
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=embedded-debug
.endif
