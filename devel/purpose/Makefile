# $NetBSD: Makefile,v 1.37 2026/01/07 08:46:44 wiz Exp $

DISTNAME=	purpose-${KF5VER}
PKGREVISION=	9
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Providing abstractions to get the developer's purposes fulfilled
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/kio/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
