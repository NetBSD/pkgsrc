# $NetBSD: Makefile,v 1.3 2003/07/17 21:49:06 grant Exp $

DISTNAME=	gpsd-1.07
CATEGORIES=	misc
MASTER_SITES=	http://www.pygps.org/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
