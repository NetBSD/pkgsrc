# $NetBSD: Makefile,v 1.6 2003/06/02 01:21:44 jschauma Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
WRKSRC=		${WRKDIR}/t20-squsq
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

MAKEFILE=	${FILESDIR}/Makefile

USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
