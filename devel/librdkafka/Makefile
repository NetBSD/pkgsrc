# $NetBSD: Makefile,v 1.12 2020/05/27 19:37:39 wiz Exp $

DISTNAME=	librdkafka-1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=edenhill/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/edenhill/librdkafka
COMMENT=	Apache Kafka C/C++ library
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c99 c++
USE_TOOLS+=	bash gmake pkg-config

CONFIG_SHELL=	bash

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-gssapi
CONFIGURE_ARGS+=	--disable-optimization
CONFIGURE_ARGS+=	--enable-lz4
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-zstd

TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	src-cpp/rdkafka++-static.pc
PKGCONFIG_OVERRIDE+=	src-cpp/rdkafka++.pc
PKGCONFIG_OVERRIDE+=	src/rdkafka-static.pc
PKGCONFIG_OVERRIDE+=	src/rdkafka.pc

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
