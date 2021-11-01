# $NetBSD: Makefile,v 1.6 2021/11/01 11:30:43 wiz Exp $

DISTNAME=	libmysofa-1.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoene/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoene/libmysofa
COMMENT=	Reader for AES SOFA HRTF files
LICENSE=	modified-bsd

TEST_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CMAKE_ARGS+=	-Wno-dev
#CMAKE_ARGS+=	-DBUILD_TESTS=OFF

PKGCONFIG_OVERRIDE+=	libmysofa.pc.cmake

# 16 test failures as of 1.1
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ctest

# for tests
BUILDLINK_DEPMETHOD.cunit=	build
.include "../../devel/cunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
