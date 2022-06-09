# $NetBSD: options.mk,v 1.4 2022/06/09 07:51:13 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-browser
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
DEFORAOS_CONFIGURE_MODE=	embedded-debug
.endif
