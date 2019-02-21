# $NetBSD: options.mk,v 1.2 2019/02/21 14:32:32 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xv
PKG_SUPPORTED_OPTIONS=	ghostscript
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# Postscript support using installed ghostscript commands
.if !empty(PKG_OPTIONS:Mghostscript)
USE_TOOLS+=	gs:run
IMAKEOPTS+=	-DUseInstalledGhostScript
.else
IMAKEOPTS+=	-UUseInstalledGhostScript
.endif
