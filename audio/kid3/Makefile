# $NetBSD: Makefile,v 1.126 2023/02/01 20:08:53 wiz Exp $

DISTNAME=	kid3-3.9.3
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kid3.sourceforge.io/
COMMENT=	ID3 tagger for QT
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:build pkg-config
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

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
