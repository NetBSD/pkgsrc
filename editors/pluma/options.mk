# $NetBSD: options.mk,v 1.2 2016/07/09 13:03:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pluma
PKG_SUPPORTED_OPTIONS=	enchant python
PKG_SUGGESTED_OPTIONS=	enchant python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	enchant python

.if !empty(PKG_OPTIONS:Menchant)
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-spell
PLIST.enchant=	yes
.else
CONFIGURE_ARGS+=	--disable-spell
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--enable-python
USE_TOOLS+=	bash:run
REPLACE_PYTHON+=	plugins/externaltools/data/switch-c.tool.in
REPLACE_BASH+=	plugins/externaltools/data/search-recursive.tool.in
PLIST.python=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gtk2, also via py-gtksourceview
.include "../../lang/python/application.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gtksourceview/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
