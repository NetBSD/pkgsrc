# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:03 jmmv Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
WRKSRC=		${WRKDIR}/t20-squsq
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

MAKEFILE=	${FILESDIR}/Makefile

USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
