# $NetBSD: Makefile,v 1.65 2022/12/06 16:14:50 adam Exp $

DISTNAME=	ccache-4.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ccache/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# Do not use xz distfile here; xz needs gettext-lib which leads to circular
# dependencies on some platforms.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccache.dev/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++17
USE_TOOLS+=	perl:test pkg-config
TEST_TARGET=	test

GCC_REQD=	8 # std::filesystem

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
