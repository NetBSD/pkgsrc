# $NetBSD: options.mk,v 1.2 2010/07/24 13:42:12 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avahi

PKG_SUPPORTED_OPTIONS=	avahi-howl gdbm python

.include "../../mk/bsd.options.mk"

###
### Enable compatibility layer for HOWL
###
.if !empty(PKG_OPTIONS:Mavahi-howl)
CONFIGURE_ARGS+=	--enable-compat-howl
PLIST_SRC+=		${PKGDIR}/PLIST.howl
.endif

###
### Enable gdbm support
###
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gdbm
.endif

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"
PY_PATCHPLIST=		yes
.  include "../../lang/python/extension.mk"
.  include "../../sysutils/py-dbus/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
DEPENDS+=		${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
### If python and gdbm are enabled we need py-gdbm as well
.  if !empty(PKG_OPTIONS:Mgdbm)
DEPENDS+=		${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
PLIST_SRC+=		${PKGDIR}/PLIST.pygdbm
.  endif
PLIST_SRC+=		${PKGDIR}/PLIST.python
.else
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-python-dbus
CONFIGURE_ARGS+=	--disable-pygtk
.endif
