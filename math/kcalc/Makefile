# $NetBSD: Makefile,v 1.59 2021/07/30 12:26:58 ryoon Exp $

DISTNAME=	kcalc-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/utilities/kcalc/
COMMENT=	KDE scientific calculator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.21.0:../../x11/kinit

USE_TOOLS+=	msgmerge

.include "../../devel/gmp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
