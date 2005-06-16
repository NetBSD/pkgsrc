# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:56 jlam Exp $

DISTNAME=	gpsd-1.07
CATEGORIES=	geography
MASTER_SITES=	http://www.pygps.org/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
