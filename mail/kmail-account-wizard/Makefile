# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:21 adam Exp $

DISTNAME=	kmail-account-wizard-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KMail account wizard
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kross/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
