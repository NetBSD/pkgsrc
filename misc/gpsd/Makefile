# $NetBSD: Makefile,v 1.2 2003/06/06 09:42:45 jmmv Exp $

DISTNAME=	gpsd-1.07
CATEGORIES=	misc
MASTER_SITES=	http://www.pygps.org/gpsd/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpsd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
