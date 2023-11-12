# $NetBSD: Makefile,v 1.56 2023/11/12 13:20:58 wiz Exp $

DISTNAME=	dolphin-plugins-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	devel sysutils

HOMEPAGE=	https://kde.org/applications/system/dolphin/
COMMENT=	Extra Dolphin plugins
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../sysutils/dolphin/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
