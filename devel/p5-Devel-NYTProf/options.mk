# $NetBSD: options.mk,v 1.1 2010/01/16 16:45:18 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Devel-NYTProf

PKG_SUPPORTED_OPTIONS=	graphviz
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	graphviz>=2:../../graphics/graphviz
.endif
