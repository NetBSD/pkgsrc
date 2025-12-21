# $NetBSD: Makefile,v 1.91 2025/12/21 13:36:49 markd Exp $

DISTNAME=	kcalc-${KAPPSVER}
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/utilities/kcalc/
COMMENT=	KDE scientific calculator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
#DEPENDS+=	kf6-kinit>=6.18.0:../../x11/kf6-kinit

USE_TOOLS+=	msgmerge

.include "../../devel/gmp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
