# $NetBSD: Makefile,v 1.1.1.1 2003/02/02 14:49:31 wulf Exp $

DISTNAME=	dvdbackup-0.1.1
WRKSRC=		${WRKDIR}/dvdbackup/src
CATEGORIES=	graphics
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@netbsd.org
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
