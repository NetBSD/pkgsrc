# $NetBSD: Makefile,v 1.5 2024/01/30 14:22:19 ryoon Exp $

DISTNAME=	kontact-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE Personal Information Manager
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kmail-account-wizard>=${KAPPSVER}:../../mail/kmail-account-wizard

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
