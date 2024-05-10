# $NetBSD: Makefile,v 1.79 2024/05/10 19:08:43 pho Exp $

DISTNAME=	libgit2-1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgit2.org/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

USE_CC_FEATURES+=	c99
FORCE_C_STD=		gnu99 # src/cli/opt.c uses alloca(3)

CMAKE_ARGS+=	-DREGEX_BACKEND="pcre2"

PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/libgit2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

BUILDLINK_TRANSFORM+=	rm:-Werror

# In some environments, two tests might fail with permission problems
# https://github.com/libgit2/libgit2/issues/6647
do-test:
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ctest

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
