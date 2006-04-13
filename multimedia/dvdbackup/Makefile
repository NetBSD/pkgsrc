# $NetBSD: Makefile,v 1.1.1.1 2006/04/13 20:14:51 wiz Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

WRKSRC=		${WRKDIR}/dvdbackup/src

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${PREFIX}/bin;

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
