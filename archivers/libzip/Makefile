# $NetBSD: Makefile,v 1.57 2021/12/08 16:01:42 adam Exp $

DISTNAME=		libzip-1.8.0
PKGREVISION=		2
CATEGORIES=		archivers devel
MASTER_SITES=		https://libzip.org/download/
MASTER_SITES+=		${MASTER_SITE_GITHUB:=nih-at/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.libzip.org/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_CMAKE=		yes
USE_TOOLS+=		perl:build

TEST_TARGET=		test
# for tests
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
