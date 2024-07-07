# $NetBSD: Makefile,v 1.25 2024/07/07 15:54:29 wiz Exp $

DISTNAME=	protobuf-c-1.5.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protobuf-c/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/protobuf-c/protobuf-c
COMMENT=	Protocol Buffers implementation in C
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	protobuf-c/libprotobuf-c.pc.in
TEST_TARGET=		check

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/include/google ${WRKSRC}/google

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
