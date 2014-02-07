# $NetBSD: Makefile,v 1.9 2014/02/07 10:19:27 wiz Exp $

DISTNAME=	libusb-1.0.9
PKGNAME=	${DISTNAME:S/libusb/libusb1/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libusb.info/
COMMENT=	USB Access Library (version 1)
LICENSE=	gnu-lgpl-v2.1

NOT_FOR_PLATFORM=	DragonFly-*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

CONFLICTS=	libusbx-[0-9]*

.include "../../mk/bsd.pkg.mk"
