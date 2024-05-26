# $NetBSD: Makefile,v 1.1 2024/05/26 12:11:38 markd Exp $

DISTNAME=	purpose-${KF6VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Providing abstractions to get the developer's purposes fulfilled
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
