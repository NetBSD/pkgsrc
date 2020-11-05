# $NetBSD: Makefile,v 1.30 2020/11/05 09:06:48 ryoon Exp $

DISTNAME=	kpeople-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/KTp/libkpeople
COMMENT=	Provides access to all contacts and aggregates them by person
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
