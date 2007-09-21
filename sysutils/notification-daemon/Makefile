# $NetBSD: Makefile,v 1.9 2007/09/21 13:04:21 wiz Exp $
#

DISTNAME=	notification-daemon-0.3.7
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notification-daemon/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Shows notification messages on the desktop

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
.include "../../devel/libsexy/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
