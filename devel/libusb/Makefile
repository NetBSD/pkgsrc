# $NetBSD: Makefile,v 1.14 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=	libusb-0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-build-docs
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
