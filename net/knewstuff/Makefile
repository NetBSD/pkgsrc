# $NetBSD: Makefile,v 1.4 2016/12/04 05:17:10 ryoon Exp $

DISTNAME=	knewstuff-${KF5VER}
PKGREVISION=	1
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for downloading application assets from the network
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
