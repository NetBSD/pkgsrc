# $NetBSD: Makefile,v 1.51 2014/05/04 08:10:12 wiz Exp $

DISTNAME=		kid3-3.1
CATEGORIES=		kde audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://kid3.sourceforge.net/
COMMENT=		ID3 tagger for QT
LICENSE=		gnu-gpl-v2

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
# seems to be ignored, so put it into LDFLAGS
CMAKE_ARGS+=		-DCMAKE_INSTALL_RPATH:PATH=${PREFIX}/lib/kid3
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/kid3

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
