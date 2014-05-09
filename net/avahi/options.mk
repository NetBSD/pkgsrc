# $NetBSD: options.mk,v 1.6 2014/05/09 07:37:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avahi
PKG_SUPPORTED_OPTIONS=	avahi-howl gdbm introspection gtk2 gtk3 mono python qt3
PKG_SUPPORTED_OPTIONS+=	qt tests
PKG_SUGGESTED_OPTIONS+=	gtk2
PLIST_VARS+=		introspection gtk2 gtk3 mono qt3 qt ui

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

.if !empty(PKG_OPTIONS:Mgtk2)
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk2=		yes
PLIST.ui=		yes
.else
CONFIGURE_ARGS+=	--disable-gtk
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
.include "../../lang/mono2/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-monodoc # XXX broken
PLIST.mono=		yes
.else
CONFIGURE_ARGS+=	--disable-mono --disable-monodoc
.endif

.if !empty(PKG_OPTIONS:Mqt3)
.include "../../x11/qt3-libs/buildlink3.mk"
PLIST.qt3=		yes
.else
CONFIGURE_ARGS+=	--disable-qt3
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt4-libs/buildlink3.mk"
PLIST.qt=		yes
.else
CONFIGURE_ARGS+=	--disable-qt4
.endif

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2
.  include "../../lang/python/application.mk"
REPLACE_PYTHON+=	avahi-python/avahi-discover/__init__.py
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

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--enable-tests
.endif
