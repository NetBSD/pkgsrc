# $NetBSD: Makefile,v 1.11 2004/07/28 02:47:35 minskim Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	${FILESDIR}/Makefile

WRKSRC=		${WRKDIR}/t20-squsq
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
