# $NetBSD: Makefile,v 1.3 2003/07/17 21:40:20 grant Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvdbackup/src
CATEGORIES=	graphics
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

USE_BUILDLINK2=	yes

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${LOCALBASE}/bin;

.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
