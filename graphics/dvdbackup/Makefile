# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:49 tv Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

WRKSRC=		${WRKDIR}/dvdbackup/src
USE_BUILDLINK3=	yes

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${LOCALBASE}/bin;

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
