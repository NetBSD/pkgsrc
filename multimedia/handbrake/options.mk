# $NetBSD: options.mk,v 1.3 2022/10/03 10:46:05 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.handbrake
PKG_SUPPORTED_OPTIONS=	gtk3

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=	gtk3
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
PLIST_SRC+=	${PKGDIR}/PLIST.gtk3
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
