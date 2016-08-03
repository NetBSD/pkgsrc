# $NetBSD: Makefile,v 1.2 2016/08/03 10:23:24 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-notification-daemon-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	Notification daemon for MATE desktop

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
