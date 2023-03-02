# $NetBSD: Makefile,v 1.64 2023/03/02 08:34:23 wiz Exp $

DISTNAME=	libgit2-1.5.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgit2/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgit2.org/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2 # linking exception (linking allowed in more ways)

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DREGEX_BACKEND="pcre2"

PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/libgit2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

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
