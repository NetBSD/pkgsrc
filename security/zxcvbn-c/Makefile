# $NetBSD: Makefile,v 1.5 2026/10/11 18:37:00 wiz Exp $

DISTNAME=	zxcvbn-c-2.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsyrogit/}
GITHUB_PROJECT=	zxcvbn-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/tsyrogit/zxcvbn-c/
COMMENT=	Password strength estimator
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

INSTALLATION_DIRS+=	include lib

# In file included from /tmp/work/security/zxcvbn-c/work/zxcvbn-c-2.7/test-internals.c:9:
# /tmp/work/security/zxcvbn-c/work/zxcvbn-c-2.7/zxcvbn.c:468:1: error: expected '}' before 'static'
MAKE_JOBS_SAFE=		no

do-install:
	${INSTALL_DATA} ${WRKSRC}/zxcvbn.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/libzxcvbn.so.0 ${DESTDIR}${PREFIX}/lib
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s libzxcvbn.so.0 libzxcvbn.so

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
