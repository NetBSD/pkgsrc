# $NetBSD: Makefile,v 1.10 2026/02/13 02:55:05 ktnb Exp $

DISTNAME=	toxcore-0.2.22
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=TokTok/}
GITHUB_PROJECT=	c-toxcore
GITHUB_TAG=	v${PKGVERSION_NOREV}

GITHUB_SUBMODULES=	camgunz cmp v20 third_party/cmp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.chat/
COMMENT=	Tox protocol library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
USE_CC_FEATURES=	c99
USE_TOOLS=		pkg-config
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
