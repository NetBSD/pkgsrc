# $NetBSD: Makefile,v 1.16 2011/04/22 13:42:14 obache Exp $
#

DISTNAME=	libnotify-0.4.5
PKGREVISION=	6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/libnotify/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Desktop notification framework

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=       dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
