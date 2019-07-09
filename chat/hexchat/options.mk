# $NetBSD: options.mk,v 1.7 2019/07/09 10:32:51 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hexchat
PKG_SUPPORTED_OPTIONS=	dbus gtk2 libcanberra libnotify libpci libproxy
PKG_SUPPORTED_OPTIONS+=	lua openssl perl python
PKG_SUGGESTED_OPTIONS+=	gtk2 libproxy openssl

PLIST_VARS+=		dbus gtk2 libpci lua perl python fishlim

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
PLIST.dbus=		yes
MESON_ARGS+=		-Dwith-dbus=true
.else
MESON_ARGS+=		-Dwith-dbus=false
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk2=		yes
MESON_ARGS+=		-Dwith-gtk=true
.else
MESON_ARGS+=		-Dwith-gtk=false
.endif

.if !empty(PKG_OPTIONS:Mlibcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
MESON_ARGS+=		-Dwith-libcanberra=true
.else
MESON_ARGS+=		-Dwith-libcanberra=false
.endif

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
MESON_ARGS+=		-Dwith-libnotify=true
.else
MESON_ARGS+=		-Dwith-libnotify=false
.endif

.if !empty(PKG_OPTIONS:Mlibpci)
.include "../../sysutils/pciutils/buildlink3.mk"
.if ${OPSYS} == "NetBSD"
LIBS+=			-lpciutils
.else
LIBS+=			-lpci
.endif
PLIST.libpci=		yes
MESON_ARGS+=		-Dwith-sysinfo=true
.else
MESON_ARGS+=		-Dwith-sysinfo=false
.endif

.if !empty(PKG_OPTIONS:Mlibproxy)
.include "../../www/libproxy/buildlink3.mk"
MESON_ARGS+=		-Dwith-libproxy=true
.else
MESON_ARGS+=		-Dwith-libproxy=false
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
MESON_ARGS+=		-Dwith-ssl=true
MESON_ARGS+=		-Dwith-fishlim=true
PLIST.fishlim=		yes
.else
MESON_ARGS+=		-Dwith-ssl=false
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
.endif
