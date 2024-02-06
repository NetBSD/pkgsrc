# $NetBSD: Makefile,v 1.53 2024/02/06 11:17:42 markd Exp $

DISTNAME=	baloo-widgets-${KAPPSVER}
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Baloo
COMMENT=	Widgets for Baloo
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../sysutils/baloo5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
