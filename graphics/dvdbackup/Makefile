# $NetBSD: Makefile,v 1.4 2004/01/20 12:18:15 agc Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

WRKSRC=		${WRKDIR}/dvdbackup/src
USE_BUILDLINK2=	yes

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${LOCALBASE}/bin;

.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
