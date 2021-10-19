# $NetBSD: options.mk,v 1.10 2021/10/19 08:17:06 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hexchat
PKG_SUPPORTED_OPTIONS=	dbus gtk2 libcanberra libpci
PKG_SUPPORTED_OPTIONS+=	lua openssl perl python

PKG_SUGGESTED_OPTIONS+=	gtk2 openssl

PLIST_VARS+=		dbus gtk2 libpci lua perl python fishlim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
PLIST.dbus=		yes
MESON_ARGS+=		-Ddbus=enabled
.else
MESON_ARGS+=		-Ddbus=disabled
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk2=		yes
MESON_ARGS+=		-Dgtk-frontend=true
.else
MESON_ARGS+=		-Dgtk-frontend=false
.endif

.if !empty(PKG_OPTIONS:Mlibcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
MESON_ARGS+=		-Dlibcanberra=enabled
.else
MESON_ARGS+=		-Dlibcanberra=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibpci)
.include "../../sysutils/pciutils/buildlink3.mk"
.  if ${OPSYS} == "NetBSD"
LIBS+=			-lpciutils
.  else
LIBS+=			-lpci
.  endif
PLIST.libpci=		yes
MESON_ARGS+=		-Dwith-sysinfo=true
.else
MESON_ARGS+=		-Dwith-sysinfo=false
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
MESON_ARGS+=		-Dwith-lua=lua
PLIST.lua=		yes
.else
MESON_ARGS+=		-Dwith-lua=false
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
MESON_ARGS+=		-Dtls=enabled
MESON_ARGS+=		-Dwith-fishlim=true
PLIST.fishlim=		yes
.else
MESON_ARGS+=		-Dtls=disabled
MESON_ARGS+=		-Dwith-fishlim=false
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl
PLIST.perl=		yes
MESON_ARGS+=		-Dwith-perl=true
.else
MESON_ARGS+=		-Dwith-perl=false
.endif

.if !empty(PKG_OPTIONS:Mpython)
PLIST.python=		yes
MESON_ARGS+=		-Dwith-python=python-${PYVERSSUFFIX}
.else
MESON_ARGS+=		-Dwith-python=false
PYTHON_FOR_BUILD_ONLY=	tool
.endif
