# $NetBSD: Makefile,v 1.20 2025/12/23 03:31:41 markd Exp $

DISTNAME=	kleopatra-${KAPPSVER}
CATEGORIES=	security

HOMEPAGE=	https://www.kde.org/applications/utilities/kleopatra/
COMMENT=	Certificate Manager and Unified Crypto GUI
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	paperkey>=1.3:../../security/paperkey

USE_TOOLS+=	msgmerge pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../mail/mimetreeparser/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
