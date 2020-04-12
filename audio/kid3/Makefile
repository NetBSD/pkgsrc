# $NetBSD: Makefile,v 1.104 2020/04/12 08:28:18 adam Exp $

DISTNAME=	kid3-3.5.1
PKGREVISION=	17
CATEGORIES=	kde audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://kid3.sourceforge.io/
COMMENT=	ID3 tagger for QT
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:build pkg-config
CMAKE_ARGS+=		-DQt5Core_DIR:PATH=${QTDIR}
CMAKE_ARGS+=		-DQT_QMAKE_EXECUTABLE:PATH=${QTDIR}/bin/qmake
CMAKE_ARGS+=		-DWITH_DOCBOOKDIR:PATH=${PREFIX}/share/xsl/docbook
CMAKE_ARGS+=		-DWITH_APPS:STRING="Qt;CLI"
CMAKE_ARGS+=		-DWITH_MANDIR:STRING=${PKGMANDIR}
# program-specific rpath is ignored since pkgsrc passes
# -DCMAKE_SKIP_RPATH:BOOL=TRUE, so re-add it manually
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/kid3

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

SUBST_CLASSES+=		apple
SUBST_MESSAGE.apple=	Avoiding Mac OS X application bundles
SUBST_STAGE.apple=	pre-configure
SUBST_FILES.apple+=	src/app/cli/CMakeLists.txt
SUBST_FILES.apple+=	src/app/qt/CMakeLists.txt
SUBST_FILES.apple+=	src/plugins/kid3qml/CMakeLists.txt
SUBST_SED.apple=	-e 's,APPLE,ELPPA,g'

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
