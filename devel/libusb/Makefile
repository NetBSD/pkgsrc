# $NetBSD: Makefile,v 1.16 2004/05/03 08:45:44 adam Exp $

DISTNAME=	libusb-0.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-build-docs
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
