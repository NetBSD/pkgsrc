# $NetBSD: Makefile,v 1.17 2014/05/15 14:41:48 adam Exp $

DISTNAME=	kajongg-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	games
COMMENT=	Maj Jong game

.include "../../meta-pkgs/kde4/Makefile.kde4"

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted

REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	src/deferredutil.py
REPLACE_PYTHON+=	src/kajongg.py
REPLACE_PYTHON+=	src/kajonggserver.py
REPLACE_PYTHON+=	src/scoringtest.py
REPLACE_PYTHON+=	src/server.py

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/py-kde4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
