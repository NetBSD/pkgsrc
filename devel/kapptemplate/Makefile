# $NetBSD: Makefile,v 1.47 2022/07/02 16:53:11 ryoon Exp $

DISTNAME=	kapptemplate-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kapptemplate/
COMMENT=	KDE Template Generator
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	gmake msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
