# $NetBSD: Makefile,v 1.6 2024/01/22 13:16:56 ryoon Exp $

DISTNAME=	toxcore-0.2.18
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=TokTok/}
GITHUB_PROJECT=	c-toxcore
GITHUB_TAG=	v${PKGVERSION_NOREV}

GITHUB_SUBMODULES=	camgunz cmp v20 third_party/cmp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tox.chat/
COMMENT=	Tox protocol library
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++
USE_TOOLS=	pkg-config
TEST_TARGET=	test

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
