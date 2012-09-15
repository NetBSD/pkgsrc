# $NetBSD: Makefile,v 1.6 2012/09/15 10:06:22 obache Exp $
#

DISTNAME=	devkitd-jmcneill-003
PKGNAME=	${DISTNAME:S/-jmcneill//}
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.invisible.ca/~jmcneill/devkitd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.invisible.ca/~jmcneill/devkitd/
COMMENT=	NetBSD port of devkitd (for DeviceKit)
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-[5-9]*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONF_FILES+=	share/examples/GConf/org.freedesktop.DeviceKit.conf \
		${PKG_SYSCONFBASEDIR}/dbus-1/system.d/org.freedesktop.DeviceKit.conf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libdevkit-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
