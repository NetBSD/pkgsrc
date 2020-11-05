# $NetBSD: Makefile,v 1.39 2020/11/05 09:06:48 ryoon Exp $

DISTNAME=	kparts-${KF5VER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Document centric plugin system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
