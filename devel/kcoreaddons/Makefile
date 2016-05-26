# $NetBSD: Makefile,v 1.1 2016/05/26 08:29:04 markd Exp $

DISTNAME=	kcoreaddons-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kf5/Makefile.common"


.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
