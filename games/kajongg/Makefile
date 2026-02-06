# $NetBSD: Makefile,v 1.100 2026/02/06 10:04:46 wiz Exp $

DISTNAME=	kajongg-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kajongg/
COMMENT=	Maj Jong game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6

USE_TOOLS+=	msgmerge

CONFIGURE_ENV+=	DESTDIR=${DESTDIR}

REPLACE_PYTHON+=	src/kajongg.py
REPLACE_PYTHON+=	src/kajonggserver.py

PLIST_SUBST+=	PYPKGVER=${PYPKGPREFIX:S/py//}

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../games/libkmahjongg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
