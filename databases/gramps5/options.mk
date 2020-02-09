# $NetBSD: options.mk,v 1.1 2020/02/09 21:43:07 jdolecek Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gramps5
PKG_SUPPORTED_OPTIONS=	graphviz freefont sqlite3
PKG_SUGGESTED_OPTIONS=	sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreefont)
DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf
.endif

.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif
