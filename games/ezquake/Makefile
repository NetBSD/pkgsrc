# $NetBSD: Makefile,v 1.2 2026/11/16 23:30:39 wiz Exp $

DISTNAME=		ezquake-source-3.6.9
PKGNAME=		${DISTNAME:S/-source//}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=QW-Group/}
GITHUB_PROJECT=		ezquake-source
GITHUB_TAG=		${PKGVERSION_NOREV}
GITHUB_SUBMODULES+=	QW-Group qwprot dd5165c1b702efeaee391b94f491cd1220018691 src/qwprot

MAINTAINER=	m.v.araujo.daniel@gmail.com
HOMEPAGE=	https://ezquake.com/
COMMENT=	Modern QuakeWorld client
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_X11=	yes

INSTALLATION_DIRS=	bin

CMAKE_ARGS+=		-DENABLE_LTO=OFF
SUBST_CLASSES+=		lto
SUBST_STAGE.lto=	pre-configure
SUBST_MESSAGE.lto=	Disabling LTO.
SUBST_FILES.lto=	CMakeLists.txt
SUBST_SED.lto=		-e 's/ENABLE_LTO.*ON/ENABLE_LTO OFF/g'

post-extract:
	${PRINTF} '{"version": "%s", "revision": "%s", "commit": "%s"}\n' \
		${PKGVERSION_NOREV} 8065 b2d448f2c5ac4be4ec40c03dcc9a018c1f837deb \
		> ${WRKSRC}/version.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmake-pkgsrc-build/ezquake-netbsd-* \
		${DESTDIR}${PREFIX}/bin/ezquake

.include "../../devel/cmake/build.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
