# $NetBSD: Makefile,v 1.3.2.2 2002/06/21 23:04:50 jlam Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

WRKSRC=		${WRKDIR}/t20-squsq
MAKEFILE=	${FILESDIR}/Makefile

USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
