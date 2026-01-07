# $NetBSD: Makefile,v 1.59 2026/01/07 08:48:52 wiz Exp $

DISTNAME=	kcron-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://apps.kde.org/en-gb/kcron/
COMMENT=	Configure and schedule tasks
LICENSE=	cc0-1.0-universal AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kirigami-addons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
