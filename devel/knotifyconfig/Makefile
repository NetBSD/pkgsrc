# $NetBSD: Makefile,v 1.9 2017/03/31 10:32:14 wiz Exp $

DISTNAME=	knotifyconfig-${KF5VER}
PKGREVISION=	6
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system for KNotify
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
