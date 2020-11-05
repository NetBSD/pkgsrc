# $NetBSD: Makefile,v 1.66 2020/11/05 09:08:09 ryoon Exp $

DISTNAME=	kajongg-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kajongg/
COMMENT=	Maj Jong game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_TOOLS+=	msgmerge

PYTHON_VERSIONS_INCOMPATIBLE=	27

CONFIGURE_ENV+=	DESTDIR=${DESTDIR}

REPLACE_PYTHON+=        src/kajongg.py
REPLACE_PYTHON+=        src/kajonggserver.py

.include "../../games/libkmahjongg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
