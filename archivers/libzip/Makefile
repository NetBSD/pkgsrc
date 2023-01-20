# $NetBSD: Makefile,v 1.62 2023/01/20 11:39:32 wiz Exp $

DISTNAME=		libzip-1.9.2
PKGREVISION=		1
CATEGORIES=		archivers devel
MASTER_SITES=		https://libzip.org/download/
MASTER_SITES+=		${MASTER_SITE_GITHUB:=nih-at/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.libzip.org/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_TOOLS+=		perl:build

TEST_TARGET=		test
# for tests
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
