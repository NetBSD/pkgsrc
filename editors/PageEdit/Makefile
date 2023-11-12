# $NetBSD: Makefile,v 1.17 2023/11/12 13:21:13 wiz Exp $

DISTNAME=	PageEdit-2.0.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sigil-Ebook/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sigil-Ebook/PageEdit/
COMMENT=	XHTML Visual Editor for ePubs
LICENSE=	gnu-gpl-v3

Qt5_DIR=	${BUILDLINK_PREFIX.qt5-qtbase}/qt5
ALL_ENV+=	Qt5_DIR=${Qt5_DIR}

BUILDLINK_TRANSFORM+=	opt:-O2:-O0

USE_LANGUAGES=	c c++0x
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

# upstream defaults to Qt6, but this needs the unpackaged qt6-webengine
CMAKE_ARGS+=	-DUSE_QT5=1

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
