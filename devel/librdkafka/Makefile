# $NetBSD: Makefile,v 1.3 2017/08/02 15:49:24 fhajny Exp $

DISTNAME=	librdkafka-0.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=edenhill/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/edenhill/librdkafka/
COMMENT=	Apache Kafka C/C++ library
LICENSE=	2-clause-bsd

GITHUB_TAG=	v${PKGVERSION_NOREV}

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c99 c++
USE_TOOLS+=	bash gmake pkg-config

CONFIG_SHELL=	bash

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-lz4
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--disable-sasl

TEST_TARGET=	check

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
