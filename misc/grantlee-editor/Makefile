# $NetBSD: Makefile,v 1.4 2023/11/12 13:22:45 wiz Exp $

DISTNAME=	grantlee-editor-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Editor for Grantlee themes
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
