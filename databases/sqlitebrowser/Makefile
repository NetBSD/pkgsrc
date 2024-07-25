# $NetBSD: Makefile,v 1.69 2024/07/25 06:47:24 adam Exp $

DISTNAME=	sqlitebrowser-3.13.0
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqlitebrowser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Qt5 lightweight GUI editor/viewer for SQLite Databases
HOMEPAGE=	https://sqlitebrowser.org/
LICENSE=	mpl-2.0 OR gnu-gpl-v3

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
