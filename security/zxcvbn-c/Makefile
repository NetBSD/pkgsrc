# $NetBSD: Makefile,v 1.2 2025/08/03 09:49:35 wiz Exp $

DISTNAME=	zxcvbn-c-2.6
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/zxcvbn.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/libzxcvbn.so.0 ${DESTDIR}${PREFIX}/lib
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s libzxcvbn.so.0 libzxcvbn.so

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
