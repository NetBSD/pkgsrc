# $NetBSD: Makefile,v 1.7 2003/03/29 12:40:01 jmmv Exp $

DISTNAME=	bunzip021.c
PKGNAME=	bunzip-0.21
WRKSRC=		${WRKDIR}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/
COMMENT=	Decompressor for bzip .bz files

USE_BUILDLINK2=		# defined

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o bunzip ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunzip ${PREFIX}/bin/bunzip

.include "../../mk/bsd.pkg.mk"
