# $NetBSD: Makefile,v 1.22 2023/10/24 22:10:32 wiz Exp $

DISTNAME=	rabbitmq-c-0.13.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=alanxz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alanxz/rabbitmq-c
COMMENT=	C-language AMQP client library for use with AMQP servers
LICENSE=	mit

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=	yes
USE_LANGUAGES=	c c99
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DBUILD_TOOLS=ON
CMAKE_ARGS+=	-DBUILD_TOOLS_DOCS=ON
CMAKE_ARGS+=	-DENABLE_SSL_SUPPORT=ON
TEST_TARGET=	test

.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
