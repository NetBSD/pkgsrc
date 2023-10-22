# $NetBSD: Makefile,v 1.1 2023/10/22 18:38:59 wiz Exp $

DISTNAME=	bkcrack-1.5.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimci86/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimci86/bkcrack/
COMMENT=	Crack legacy zip encryption with Biham and Kocher's known plaintext attack
LICENSE=	zlib

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin share/doc/bkcrack share/examples/bkcrack

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} bkcrack bin
	cd ${DESTDIR}${PREFIX} && ${MV} example/* share/examples/bkcrack
	cd ${DESTDIR}${PREFIX} && ${MV} [lrt]* share/doc/bkcrack

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
