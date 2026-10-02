# $NetBSD: Makefile,v 1.12 2026/10/02 05:17:13 fox Exp $

DISTNAME=	libdecaf-1.0.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ed448goldilocks/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://ed448goldilocks.sourceforge.net/
COMMENT=	Implementation of Ed448-Goldilocks elliptic curve for cryptography
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTS=YES
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

BUILDLINK_TRANSFORM+=	rm:-Werror

# These are required to prevent build breakage when tests are enabled
# This is probably due to the auto-generated headers clobbering with
# the #defines
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PYTHON_FOR_BUILD_ONLY=		tool

# XXX: Avoid to pick up possibe installed libdecaf.so
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src

TEST_TARGET=	test

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libdecaf.a

.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
