# $NetBSD: options.mk,v 1.1 2008/06/09 19:35:31 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nmap

PKG_SUPPORTED_OPTIONS=	zenmap

.include "../../mk/bsd.options.mk"

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
.else
CONFIGURE_ARGS+=	--without-zenmap
.endif
