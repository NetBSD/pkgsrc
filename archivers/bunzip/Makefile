# $NetBSD: Makefile,v 1.1.1.1 1999/05/23 20:55:29 tv Exp $

DISTNAME=	bunzip021.c
PKGNAME=	bunzip-0.21
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/

NO_WRKSUBDIR=
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} >${DISTNAME}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o bunzip ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunzip ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
