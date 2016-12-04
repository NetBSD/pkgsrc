# $NetBSD: Makefile,v 1.2 2016/12/04 05:17:06 ryoon Exp $

DISTNAME=	kpeople-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	http://community.kde.org/KTp/libkpeople
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
