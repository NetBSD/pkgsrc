# $NetBSD: Makefile,v 1.8 2002/08/21 11:05:28 wiz Exp $
#

DISTNAME=	libusb-0.1.6a
PKGNAME=	${DISTNAME:S/a/.1/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
