# $NetBSD: Makefile,v 1.21 2005/02/24 18:46:49 drochner Exp $

DISTNAME=	libusb-0.1.10a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
GCC_REQD=		3.3
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-docs

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*

.include "../../mk/bsd.pkg.mk"
