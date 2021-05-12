# $NetBSD: options.mk,v 1.10 2021/05/12 06:30:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng python
PKG_SUGGESTED_OPTIONS=	mng python

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}
PLIST_VARS+=		aalib mng

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Mpython)
PLIST_SRC+=		PLIST.python
PYTHON_VERSIONS_ACCEPTED=	27
CONFIGURE_ARGS+=		--enable-python
REPLACE_PYTHON+=		plug-ins/pygimp/*.py
REPLACE_PYTHON+=		plug-ins/pygimp/plug-ins/*.py
REPLACE_PYTHON+=		plug-ins/pygimp/plug-ins/*/*.py
REPLACE_PYTHON+=		tools/*.py
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/py-cairo118/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.else
CONFIGURE_ARGS+=		--disable-python
.endif
