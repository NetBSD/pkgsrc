# $NetBSD: Makefile,v 1.4 2024/11/01 00:51:23 wiz Exp $

DISTNAME=	kcolorscheme-${KF6VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Classes to read and interact with KColorScheme
LICENSE=	gnu-lgpl-v2.1 AND cc0-1.0-universal AND 2-clause-bsd

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
