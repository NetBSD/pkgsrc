# $NetBSD: Makefile,v 1.5 2009/08/22 22:05:23 abs Exp $

DISTNAME=	dvdbackup-0.1.1
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://dvd-create.sourceforge.net/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://dvd-create.sourceforge.net/
COMMENT=	DVD backup utility

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/dvdbackup/src

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}; \
	${CC} -o dvdbackup dvdbackup.c ${CFLAGS} ${LDFLAGS} -ldvdread

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dvdbackup ${DESTDIR}${PREFIX}/bin;
	${INSTALL_MAN} ${FILESDIR}/dvdbackup.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
