# $NetBSD: Makefile,v 1.19 2026/01/07 08:47:46 wiz Exp $

DISTNAME=	kmail-account-wizard-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KMail account wizard
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
