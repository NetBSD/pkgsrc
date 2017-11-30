# $NetBSD: Makefile,v 1.14 2017/11/30 16:45:02 adam Exp $

DISTNAME=	knotifyconfig-${KF5VER}
PKGREVISION=	11
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system for KNotify
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
