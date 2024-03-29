# $NetBSD: Makefile,v 1.5 2023/08/14 05:25:10 wiz Exp $

DISTNAME=	mbedtls-3.4.0
PKGNAME=	${DISTNAME:S/mbedtls/mbedtls3/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARMmbed/}
GITHUB_PROJECT=	mbedtls
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://tls.mbed.org/
COMMENT=	Lightweight, modular cryptographic and SSL/TLS library (3.x branch)
LICENSE=	apache-2.0

CONFLICTS+=	mbedtls-[0-9]*
CONFLICTS+=	polarssl-[0-9]*
SUPERSEDES+=	polarssl-[0-9]*

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

GCC_REQD+=	4.4

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DUSE_SHARED_MBEDTLS_LIBRARY=ON
CMAKE_ARGS+=	-DENABLE_PROGRAMS=ON

# Fails to build full suite on NetBSD due to strange tricks with stdout
CMAKE_ARGS+=	-DENABLE_TESTING=OFF

CMAKE_ARGS+=	-DMBEDTLS_FATAL_WARNINGS=OFF

MAKE_ENV+=	RANLIB=${RANLIB:Q}

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Prefix bundled programs so they don't conflict with other packages
post-install:
	cd ${DESTDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

do-test:
	LD_LIBRARY_PATH=${WRKSRC}/library \
	    ${WRKSRC}/programs/test/selftest

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
