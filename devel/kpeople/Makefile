# $NetBSD: Makefile,v 1.9 2018/01/17 20:00:21 markd Exp $

DISTNAME=	kpeople-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/KTp/libkpeople
COMMENT=	Provides access to all contacts and aggregates them by person
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
