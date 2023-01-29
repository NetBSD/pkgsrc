# $NetBSD: Makefile,v 1.42 2023/01/29 21:14:58 ryoon Exp $

DISTNAME=	baloo-widgets-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Baloo
COMMENT=	Widgets for Baloo
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
