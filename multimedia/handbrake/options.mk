# $NetBSD: options.mk,v 1.4 2025/08/30 04:45:32 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.handbrake
PKG_SUPPORTED_OPTIONS=	gtk4

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=	gtk4
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk4)
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
PLIST_SRC+=	${PKGDIR}/PLIST.gtk4
post-build: post-build-gtk4
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
