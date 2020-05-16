# $NetBSD: Makefile,v 1.16 2020/05/16 16:16:10 rillig Exp $

DISTNAME=	rabbitmq-c-0.10.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alanxz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=		yes
USE_LANGUAGES=		c c99
USE_TOOLS+=		pkg-config
CMAKE_ARGS+=		-DBUILD_TOOLS=ON
CMAKE_ARGS+=		-DBUILD_TOOLS_DOCS=ON
CMAKE_ARGS+=		-DENABLE_SSL_SUPPORT=ON
TEST_TARGET=		test

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
