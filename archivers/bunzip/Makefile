# $NetBSD: Makefile,v 1.11 2004/02/08 04:03:15 jlam Exp $

DISTNAME=	bunzip021.c
PKGNAME=	bunzip-0.21
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/
COMMENT=	Decompressor for bzip .bz files

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	# defined

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o bunzip ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunzip ${PREFIX}/bin/bunzip

.include "../../mk/bsd.pkg.mk"
