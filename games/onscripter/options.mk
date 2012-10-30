# $NetBSD: options.mk,v 1.1 2012/10/30 16:09:53 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.onscripter
PKG_SUPPORTED_OPTIONS=	onscripter-pda
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Monscripter-pda)
# Enable PDA_AUTOSIZE option to fit window size to screen on small PDA devices
PDA_DEFS=	-DPDA_AUTOSIZE
.else
PDA_DEFS=
.endif
