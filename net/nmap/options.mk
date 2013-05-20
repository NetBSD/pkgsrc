# $NetBSD: options.mk,v 1.9 2013/05/20 06:21:22 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	inet6 ndiff zenmap
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ndiff zenmap

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mndiff)
CONFIGURE_ARGS+=	--with-ndiff
PLIST.ndiff=		yes
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	ndiff/setup.py
SUBST_SED.paths=	-e "s|@@PKGMANDIR@@|${PKGMANDIR}|g"
SUBST_MESSAGE.paths=	Fixing paths.
.include "../../lang/python/application.mk"
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
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=	--without-zenmap
.endif
