# $NetBSD: Makefile,v 1.8 2012/10/23 19:51:10 asau Exp $
#

DISTNAME=	DeviceKit-003
PKGNAME=	${DISTNAME:S/DeviceKit/libdevkit-gobject/}
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/DeviceKit
COMMENT=	Modular hardware abstraction layer
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
# needs udev support, which currently only exists on Linux
# for NetBSD, use the devkitd package
# XXX: fix PLIST for Linux
CONFIGURE_ARGS+=	--disable-devkitd
.endif

PKGCONFIG_OVERRIDE+=	src/devkit-gobject/devkit-gobject.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

BUILDLINK_DEPMETHOD.libxslt=		build
BUILDLINK_DEPMETHOD.docbook-xsl=	build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/docbook-xsl/buildlink3.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
