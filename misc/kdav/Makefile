# $NetBSD: Makefile,v 1.50 2026/01/07 08:47:57 wiz Exp $

DISTNAME=	kdav-${KF5VER}
PKGREVISION=	9
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	DAV protocol implemention with KJobs
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
