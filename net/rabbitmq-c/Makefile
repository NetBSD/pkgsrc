# $NetBSD: Makefile,v 1.13 2018/12/15 21:12:22 wiz Exp $

DISTNAME=	rabbitmq-c-0.9.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alanxz/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

GITHUB_TAG=	v${PKGVERSION_NOREV}

BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=		yes
USE_LANGUAGES=		c c99
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fix man installation path
SUBST_FILES.man+=	tools/CMakeLists.txt tools/cmake_install.cmake
SUBST_SED.man=		-e "s|share/man|${PKGMANDIR}|g"

CMAKE_ARGS+=		-DBUILD_TOOLS=ON
CMAKE_ARGS+=		-DBUILD_TOOLS_DOCS=ON
CMAKE_ARGS+=		-DENABLE_SSL_SUPPORT=ON

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
