# $NetBSD: Makefile,v 1.1 2024/05/26 11:19:45 markd Exp $

DISTNAME=	kcolorscheme-${KF6VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Classes to read and interact with KColorScheme
LICENSE=	gnu-lgpl-v2.1 AND cc0-1.0-universal AND 2-clause-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
