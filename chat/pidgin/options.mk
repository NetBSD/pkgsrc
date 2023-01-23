# $NetBSD: options.mk,v 1.22 2023/01/23 21:05:39 triaxx Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		dbus debug gtkspell
PKG_SUGGESTED_OPTIONS+=		dbus gtkspell

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin" || !exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=		x11
PKG_SUGGESTED_OPTIONS+=		x11
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus x11

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
PYTHON_FOR_BUILD_ONLY=	tool
.  include "../../lang/python/tool.mk"
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtkspell)
CONFIGURE_ARGS+=	--enable-gtkspell
.  include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
