# $NetBSD: Makefile,v 1.13 2023/02/21 09:01:28 adam Exp $

DISTNAME=	librsync-2.3.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=librsync/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librsync.sourcefrog.net/
COMMENT=	Rsync-like rolling checksum library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl pkg-config
TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
