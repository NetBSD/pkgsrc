# $NetBSD: Makefile,v 1.14 2006/09/09 02:41:54 obache Exp $

DISTNAME=	t20-squsq-3.3
PKGNAME=	squsq-3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compressor/decompressor for CP/M Squeeze compressed files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=	${FILESDIR}/Makefile

WRKSRC=		${WRKDIR}/t20-squsq

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sq ${WRKSRC}/usq ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
