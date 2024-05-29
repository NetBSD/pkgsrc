# $NetBSD: Makefile,v 1.8 2024/05/29 16:34:16 adam Exp $

DISTNAME=	kleopatra-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	security

HOMEPAGE=	https://www.kde.org/applications/utilities/kleopatra/
COMMENT=	Certificate Manager and Unified Crypto GUI
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	paperkey>=1.3:../../security/paperkey

USE_TOOLS+=	msgmerge

USE_CXX_FEATURES+=	c++20

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
