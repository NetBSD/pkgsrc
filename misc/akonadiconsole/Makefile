# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:30 adam Exp $

DISTNAME=	akonadiconsole-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Akonadi management and debugging console
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../time/calendarsupport/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
