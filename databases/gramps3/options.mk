# $NetBSD: options.mk,v 1.4 2014/05/09 07:36:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gramps3
PKG_SUPPORTED_OPTIONS=	graphviz enchant freefont

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menchant)
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-ORBit via py-gnome2
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfreefont)
DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf
.endif

.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
.endif
