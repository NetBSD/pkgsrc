# $NetBSD: Makefile,v 1.27 2012/09/15 10:06:30 obache Exp $
#

DISTNAME=	notification-daemon-0.4.0
PKGREVISION=	14
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notification-daemon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Shows notification messages on the desktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

GCONF_SCHEMAS=	notification-daemon.schemas

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_SYSCONFDIR.dbus)
CONFIGURE_ARGS+=	--with-dbus-sys=${PKG_SYSCONFDIR.dbus}/system.d
.else
CONFIGURE_ARGS+=	--with-dbus-sys=${PKG_SYSCONFDIR}/dbus-1/system.d
.endif

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
