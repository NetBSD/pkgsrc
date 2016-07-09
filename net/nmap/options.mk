# $NetBSD: options.mk,v 1.16 2016/07/09 13:03:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	inet6 ndiff zenmap lua
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ndiff zenmap lua

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mndiff)
CONFIGURE_ARGS+=	--with-ndiff
PLIST.ndiff=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	ndiff/*.py
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	ndiff/setup.py
SUBST_VARS.paths=	PKGMANDIR
SUBST_MESSAGE.paths=	Fixing paths.
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=		--without-ndiff
.endif

# Enable dynamically loadable preprocessors, detection engine
# and rules libraries.
.if !empty(PKG_OPTIONS:Mzenmap)
CONFIGURE_ARGS+=	--with-zenmap
PLIST.zenmap=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	zenmap/zenmapCore/*.py
REPLACE_PYTHON+=	zenmap/zenmapGUI/*.py
REPLACE_PYTHON+=	zenmap/zenmapGUI/higwidgets/*.py
REPLACE_PYTHON+=	zenmap/test/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-xml, py-sqlite2, py-gtk2
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=	--without-zenmap
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liblua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--without-liblua
.endif
