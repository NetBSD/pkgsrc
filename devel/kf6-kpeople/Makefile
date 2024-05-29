# $NetBSD: Makefile,v 1.2 2024/05/29 16:32:09 adam Exp $

DISTNAME=	kpeople-${KF6VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/KTp/libkpeople
COMMENT=	Provides access to all contacts and aggregates them by person
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
