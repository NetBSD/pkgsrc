# $NetBSD: Makefile,v 1.68 2023/01/29 21:17:10 ryoon Exp $

DISTNAME=	klettres-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/klettres/
COMMENT=	KDE app to teach the alphabet and read some syllables in languages
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
