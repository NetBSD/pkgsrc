# $NetBSD: Makefile,v 1.3 2003/06/18 09:22:15 agc Exp $

DISTNAME=	cd-discid_0.7.orig
PKGNAME=	cd-discid-0.7
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/cd-discid/

MAINTAINER=	lukem@netbsd.org
COMMENT=	Read CD to obtain CDDB discid information

do-build:
	cd ${WRKSRC} && ${CC} -O -o cd-discid cd-discid.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cd-discid ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cd-discid.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
