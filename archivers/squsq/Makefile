# $NetBSD: Makefile,v 1.9 2004/03/11 18:03:50 xtraeme Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

MAKEFILE=	${FILESDIR}/Makefile

WRKSRC=		${WRKDIR}/t20-squsq
USE_BUILDLINK3=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
