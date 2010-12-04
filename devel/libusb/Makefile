# $NetBSD: Makefile,v 1.30 2010/12/04 08:12:33 adam Exp $

DISTNAME=	libusb-0.1.12
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-docs
PKGCONFIG_OVERRIDE+=	libusb.pc.in

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*-*

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
