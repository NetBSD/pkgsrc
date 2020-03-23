# $NetBSD: options.mk,v 1.17 2020/03/23 15:56:55 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avahi
PKG_SUPPORTED_OPTIONS=	avahi-howl gdbm introspection gtk3 mono python
PKG_SUPPORTED_OPTIONS+=	tests
PKG_SUGGESTED_OPTIONS+=	gtk3
PLIST_VARS+=		introspection gtk3 mono ui

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

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
PLIST.gtk3=		yes
PLIST.ui=		yes
.else
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mmono)
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-monodoc # XXX broken
PLIST.mono=		yes
.else
CONFIGURE_ARGS+=	--disable-mono --disable-monodoc
.endif

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=		yes
.  include "../../lang/python/application.mk"
REPLACE_PYTHON+=	avahi-python/avahi-discover/__init__.py
.  include "../../lang/python/extension.mk"
.  include "../../sysutils/py-dbus/buildlink3.mk"
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
.endif

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--enable-tests
.endif
