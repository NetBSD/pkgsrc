# $NetBSD: Makefile,v 1.12 2015/08/22 21:23:46 leot Exp $

DISTNAME=	libusb-1.0.19
PKGNAME=	${DISTNAME:S/libusb/libusb1/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libusb.info/
COMMENT=	USB Access Library (version 1)
LICENSE=	gnu-lgpl-v2.1

# Solaris doesn't support the hardware-level interface (IIRC).
# Works on Dragonfly but explicitly not wanted by DragonFly upstream;
# see PR 47042.
NOT_FOR_PLATFORM=	DragonFly-*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

CONFIGURE_ARGS+=	--enable-tests-build

CONFLICTS=	libusbx-[0-9]*

do-test:
	cd ${WRKSRC}/tests && ./stress

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
