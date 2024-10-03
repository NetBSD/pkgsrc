# $NetBSD: Makefile,v 1.23 2024/10/03 13:24:05 rhialto Exp $

DISTNAME=	cbmconvert-2.1.6
CATEGORIES=	converters archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=dr-m/}
GITHUB_PROJECT=	cbmconvert
GITHUB_TAG=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dr-m/cbmconvert/
COMMENT=	Converts files to and from various C64/C128/CBM formats
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c

#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/cbmconvert

do-test:
	cd ${WRKSRC} && ctest -C Debug

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
