# $NetBSD: Makefile,v 1.2 2012/07/20 11:30:51 marino Exp $

DISTNAME=	libusbx-1.0.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusbx/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libusbx.sourceforge.net/
COMMENT=	USB Access Library (version 1) for of libusb
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	DragonFly-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

CONFLICTS=	libusb1-[0-9]*

.include "../../mk/bsd.pkg.mk"
