# $NetBSD: Makefile,v 1.7 2017/09/18 09:52:59 maya Exp $

DISTNAME=	kpeople-${KF5VER}
PKGREVISION=	5
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
