# $NetBSD: Makefile,v 1.17 2013/01/21 22:24:55 jperkin Exp $

DISTNAME=	cd-discid_0.9.orig
PKGNAME=	cd-discid-0.9
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read CD to obtain CDDB discid information
HOMEPAGE=	http://linukz.org/cd-discid.shtml
LICENSE=	gnu-gpl-v2

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
