# $NetBSD: Makefile,v 1.79 2024/01/30 14:22:15 ryoon Exp $

DISTNAME=	analitza-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	math

HOMEPAGE=	https://edu.kde.org/
COMMENT=	KDE library for mathematical features
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

.include "../../math/eigen3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
