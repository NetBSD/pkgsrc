# $NetBSD: Makefile,v 1.84 2024/10/22 09:47:50 adam Exp $

DISTNAME=	libgit2-1.8.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgit2.org/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
FORCE_C_STD=		gnu99 # src/cli/opt.c uses alloca(3)
# In some environments, two tests might fail with permission problems
# https://github.com/libgit2/libgit2/issues/6647
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DREGEX_BACKEND="pcre2"

PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/libgit2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
# for tests
.include "../../lang/python/pyversion.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
