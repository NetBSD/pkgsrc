# $NetBSD: Makefile,v 1.16 2012/09/11 23:59:28 asau Exp $

DISTNAME=	cd-discid_0.9.orig
PKGNAME=	cd-discid-0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read CD to obtain CDDB discid information
HOMEPAGE=	http://linukz.org/cd-discid.shtml

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CC} -O -o cd-discid cd-discid.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
