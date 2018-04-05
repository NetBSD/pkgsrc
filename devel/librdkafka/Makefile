# $NetBSD: Makefile,v 1.6 2018/04/05 09:01:16 fhajny Exp $

DISTNAME=	librdkafka-0.11.4
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

PKGCONFIG_OVERRIDE+=	src-cpp/rdkafka++-static.pc
PKGCONFIG_OVERRIDE+=	src-cpp/rdkafka++.pc
PKGCONFIG_OVERRIDE+=	src/rdkafka-static.pc
PKGCONFIG_OVERRIDE+=	src/rdkafka.pc

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
