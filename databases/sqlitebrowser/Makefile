# $NetBSD: Makefile,v 1.64 2023/11/08 13:18:37 wiz Exp $

DISTNAME=	sqlitebrowser-3.12.2
PKGREVISION=	15
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sqlitebrowser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Qt5 lightweight GUI editor/viewer for SQLite Databases
HOMEPAGE=	https://sqlitebrowser.org/
LICENSE=	mpl-2.0 OR gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

USE_CXX_FEATURES+=	c++11

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
