# $NetBSD: Makefile,v 1.3 2026/01/27 08:39:47 wiz Exp $

DISTNAME=	aurorae-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Themeable window decoration for KWin
LICENSE=	gnu-gpl-v2 AND mit

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge pkg-config

REPLACE_SH+=	src/plasma-apply-aurorae.cmake

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kpackage/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/kf6-ksvg/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/plasma6-kdecoration/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
