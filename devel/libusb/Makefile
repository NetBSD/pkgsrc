# $NetBSD: Makefile,v 1.25 2005/12/05 20:50:05 rillig Exp $

DISTNAME=	libusb-0.1.10a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-docs

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*-*

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
