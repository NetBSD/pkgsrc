# $NetBSD: Makefile,v 1.2 2006/04/17 13:46:10 wiz Exp $
#

DISTNAME=	libnotify-0.3.2
PKGREVISION=	1
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
.include "../../devel/popt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
