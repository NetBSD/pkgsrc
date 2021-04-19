# $NetBSD: Makefile,v 1.65 2021/04/19 10:59:23 nia Exp $

DISTNAME=	jasper
PKGNAME=	jasper-2.0.32
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jasper-software/}
GITHUB_RELEASE=	version-${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://jasper-software.github.io/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/jasper-${GITHUB_TAG}
USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
USE_TOOLS+=		bash:test
CMAKE_ARGS+=		-DALLOW_IN_SOURCE_BUILD=ON
CMAKE_ARGS+=		-DJAS_ENABLE_DOC=OFF

PKGCONFIG_OVERRIDE=	build/jasper.pc.in
REPLACE_BASH=		test/bin/*
TEST_TARGET=		test

.include "options.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
