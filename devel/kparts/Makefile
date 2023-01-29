# $NetBSD: Makefile,v 1.56 2023/01/29 21:14:28 ryoon Exp $

DISTNAME=	kparts-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Document centric plugin system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	gmake msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
