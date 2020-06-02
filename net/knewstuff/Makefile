# $NetBSD: Makefile,v 1.39 2020/06/02 08:22:52 adam Exp $

DISTNAME=	knewstuff-${KF5VER}
PKGREVISION=	4
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for downloading application assets from the network
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
