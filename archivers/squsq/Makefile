# $NetBSD: Makefile,v 1.2 2001/02/16 13:15:36 wiz Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

WRKSRC=		${WRKDIR}/t20-squsq
MAKEFILE=	${FILESDIR}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
