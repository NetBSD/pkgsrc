# $NetBSD: Makefile,v 1.24 2024/08/25 06:19:07 wiz Exp $

DISTNAME=	rabbitmq-c-0.14.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alanxz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_CC_FEATURES=	c99

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TOOLS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TOOLS_DOCS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SSL_SUPPORT=ON
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
