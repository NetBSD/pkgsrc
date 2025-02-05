# $NetBSD: Makefile,v 1.1 2025/02/05 22:25:37 markd Exp $

DISTNAME=	kstatusnotifieritem-${KF6VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Implementation of Status Notifier Items
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
