# $NetBSD: Makefile,v 1.1.1.1 2004/07/26 23:31:56 wiz Exp $

DISTNAME=	gpsd-1.07
CATEGORIES=	geography
MASTER_SITES=	http://www.pygps.org/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
