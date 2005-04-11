# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:01 tv Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

WRKSRC=		${WRKDIR}/dvdbackup/src

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${LOCALBASE}/bin;

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
