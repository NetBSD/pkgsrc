# $NetBSD: Makefile,v 1.7 2003/07/17 21:21:38 grant Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
WRKSRC=		${WRKDIR}/t20-squsq
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

MAKEFILE=	${FILESDIR}/Makefile

USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
