# $NetBSD: options.mk,v 1.4 2010/03/21 21:58:23 pettai Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	inet6 zenmap ndiff
PKG_SUGGESTED_OPTIONS=	inet6

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
PYTHON_VERSIONS_ACCEPTED=	26 25 24
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
PYTHON_VERSIONS_ACCEPTED=	26 25 24
.else
CONFIGURE_ARGS+=		--without-ndiff
.endif
