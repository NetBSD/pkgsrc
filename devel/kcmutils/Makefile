# $NetBSD: Makefile,v 1.14 2017/09/18 09:52:58 maya Exp $

DISTNAME=	kcmutils-${KF5VER}
PKGREVISION=	10
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Utilities for interacting with KCModules
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
