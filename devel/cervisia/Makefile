# $NetBSD: Makefile,v 1.56 2020/11/05 09:07:51 ryoon Exp $

DISTNAME=	cervisia-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/cervisia/
COMMENT=	CVS frontend
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.19.0:../../x11/kinit

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../security/kdesu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
