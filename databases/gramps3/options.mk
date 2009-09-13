# $NetBSD: options.mk,v 1.1 2009/09/13 14:43:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gramps3
PKG_SUPPORTED_OPTIONS=	graphviz enchant freefont
PKG_SUGGESTED_OPTIONS=	graphviz enchant freefont

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menchant)
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfreefont)
DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf
.endif

.if !empty(PKG_OPTIONS:Mgraphviz)
.include "../../graphics/graphviz/buildlink3.mk"
.endif
