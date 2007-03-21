# $NetBSD: Makefile,v 1.6 2007/03/21 22:33:59 wiz Exp $
#

DISTNAME=	libnotify-0.4.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/libnotify/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Desktop notification framework

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
