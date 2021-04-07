# $NetBSD: Makefile,v 1.58 2021/04/07 12:28:27 markd Exp $

DISTNAME=	kig-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kig/
COMMENT=	KDE interactive geometry
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

REPLACE_PYTHON+=	pykig/pykig.py

.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
