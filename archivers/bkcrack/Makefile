# $NetBSD: Makefile,v 1.3 2024/12/24 12:00:24 adam Exp $

DISTNAME=	bkcrack-1.7.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimci86/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimci86/bkcrack
COMMENT=	Crack legacy zip encryption
LICENSE=	zlib

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin share/doc/bkcrack share/examples/bkcrack

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} bkcrack bin
	cd ${DESTDIR}${PREFIX} && ${MV} example/* share/examples/bkcrack
	cd ${DESTDIR}${PREFIX} && ${MV} [lrt]* share/doc/bkcrack

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
