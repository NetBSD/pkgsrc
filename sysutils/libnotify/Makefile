# $NetBSD: Makefile,v 1.25 2012/10/23 19:51:10 asau Exp $

DISTNAME=	libnotify-0.4.5
PKGREVISION=	13
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/libnotify/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
