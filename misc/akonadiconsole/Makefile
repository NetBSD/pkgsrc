# $NetBSD: Makefile,v 1.18 2025/12/21 13:43:44 markd Exp $

DISTNAME=	akonadiconsole-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Akonadi management and debugging console
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../time/calendarsupport/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
