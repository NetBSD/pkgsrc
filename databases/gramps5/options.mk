# $NetBSD: options.mk,v 1.2 2023/10/23 06:37:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gramps5
PKG_SUPPORTED_OPTIONS=	graphviz freefont
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreefont)
DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf
.endif

.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
.endif
