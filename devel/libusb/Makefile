# $NetBSD: Makefile,v 1.1.1.1 2001/03/28 10:11:41 drochner Exp $
#

DISTNAME=	libusb-0.1.3b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
