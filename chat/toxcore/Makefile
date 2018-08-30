# $NetBSD: Makefile,v 1.1 2018/07/30 18:58:43 jperkin Exp $

DISTNAME=	toxcore-0.2.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=TokTok/}
GITHUB_PROJECT=	c-toxcore
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
