# $NetBSD: options.mk,v 1.1 2012/07/26 22:15:08 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dc-tools
PKG_SUPPORTED_OPTIONS=	gxemul
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgxemul)
DEPENDS+=	gxemul>=0.6.0nb3:../../emulators/gxemul
.endif
