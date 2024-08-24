# $NetBSD: Makefile,v 1.50 2024/08/24 05:28:59 markd Exp $

DISTNAME=	kcron-${KAPPSVER}
CATEGORIES=	sysutils

HOMEPAGE=	https://apps.kde.org/en-gb/kcron/
COMMENT=	Configure and schedule tasks
LICENSE=	cc0-1.0-universal AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../security/kauth/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
