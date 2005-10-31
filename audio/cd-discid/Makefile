# $NetBSD: Makefile,v 1.10 2005/10/31 15:07:00 tv Exp $

DISTNAME=	cd-discid_0.9.orig
PKGNAME=	cd-discid-0.9
CATEGORIES=	audio
MASTER_SITES=	http://lly.org/~rcw/cd-discid/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Read CD to obtain CDDB discid information

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

NOT_FOR_PLATFORM=	Interix-*-*

INSTALLATION_DIRS=	bin man/man1

do-build:
	cd ${WRKSRC} && ${CC} -O -o cd-discid cd-discid.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
