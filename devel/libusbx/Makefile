# $NetBSD: Makefile,v 1.6 2015/01/04 02:52:03 dholland Exp $

DISTNAME=	libusbx-1.0.18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusbx/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libusbx.org/
COMMENT=	USB Access Library (version 1) for of libusb
LICENSE=	gnu-lgpl-v2.1

# Not wanted by Dragonfly upstream; use Dragonfly's native libusb instead.
NOT_FOR_PLATFORM=	DragonFly-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

CONFLICTS=	libusb1-[0-9]*

.include "../../mk/bsd.pkg.mk"
