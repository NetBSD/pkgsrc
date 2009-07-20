# $NetBSD: options.mk,v 1.3 2009/07/20 19:40:08 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	zenmap inet6 ndiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Enable dynamically loadable preprocessors, detection engine
### and rules libraries.
###
.if !empty(PKG_OPTIONS:Mzenmap)
CONFIGURE_ARGS+=		--with-zenmap
PLIST_SRC+=			${PKGDIR}/PLIST.zenmap
PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=			yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=	--without-zenmap
.endif

.if !empty(PKG_OPTIONS:Mndiff)
CONFIGURE_ARGS+=		--with-ndiff
PLIST_SRC+=			${PKGDIR}/PLIST.ndiff
PYTHON_VERSIONS_ACCEPTED=	25 24
.else
CONFIGURE_ARGS+=		--without-ndiff
.endif
