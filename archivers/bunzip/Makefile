# $NetBSD: Makefile,v 1.5 2002/02/25 04:47:21 jlam Exp $

DISTNAME=	bunzip021.c
PKGNAME=	bunzip-0.21
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muraroa.demon.co.uk/
COMMENT=	Decompressor for bzip .bz files

USE_BUILDLINK_ONLY=	# defined
WRKSRC=			${WRKDIR}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o bunzip ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunzip ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
