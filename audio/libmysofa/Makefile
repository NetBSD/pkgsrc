# $NetBSD: Makefile,v 1.7 2022/12/03 08:47:28 adam Exp $

DISTNAME=	libmysofa-1.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoene/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoene/libmysofa
COMMENT=	Reader for AES SOFA HRTF files
LICENSE=	modified-bsd

TEST_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-Wno-dev

PKGCONFIG_OVERRIDE+=	libmysofa.pc.cmake

# 16 test failures as of 1.1
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ctest

# for tests
BUILDLINK_DEPMETHOD.cunit=	build
.include "../../devel/cunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
