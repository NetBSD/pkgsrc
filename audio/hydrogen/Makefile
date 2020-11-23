# $NetBSD: Makefile,v 1.67 2020/11/23 14:09:06 nia Exp $

DISTNAME=	hydrogen-1.0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hydrogen-music/}
GITHUB_PROJECT=	Hydrogen
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/.rc/-rc/}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

# C++14
GCC_REQD+=	5

CMAKE_ARGS+=	-DWANT_LRDF=ON

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
CMAKE_ARGS+=	-DWANT_OSS=ON
.else
CMAKE_ARGS+=	-DWANT_OSS=OFF
.endif

CMAKE_ARGS+=	-DWANT_CPPUNIT=OFF

LDFLAGS.SunOS+=	-lsocket -lnsl

# It rejectes the genreated .pc file for NetBSD libarchive.
PREFER.libarchive=	pkgsrc

.include "options.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
