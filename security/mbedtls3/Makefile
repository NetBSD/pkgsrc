# $NetBSD: Makefile,v 1.8 2025/01/21 11:00:17 nia Exp $

DISTNAME=	mbedtls-3.6.2
PKGNAME=	${DISTNAME:S/mbedtls/mbedtls3/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mbed-TLS/mbedtls/releases/download/mbedtls-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tls.mbed.org/
COMMENT=	Lightweight, modular cryptographic and SSL/TLS library (3.x branch)
LICENSE=	apache-2.0 OR gnu-gpl-v2

CONFLICTS+=	mbedtls-[0-9]*
CONFLICTS+=	polarssl-[0-9]*
SUPERSEDES+=	polarssl-[0-9]*

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

GCC_REQD+=	4.4

CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DUSE_SHARED_MBEDTLS_LIBRARY=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PROGRAMS=ON

# Fails to build full suite on NetBSD due to strange tricks with stdout
CMAKE_CONFIGURE_ARGS.NetBSD+=	-DENABLE_TESTING=OFF

CMAKE_CONFIGURE_ARGS+=	-DMBEDTLS_FATAL_WARNINGS=OFF

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
