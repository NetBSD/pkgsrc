# $NetBSD: Makefile,v 1.63 2022/08/11 05:09:01 gutteridge Exp $

DISTNAME=	kcharselect-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/utilities/kcharselect/
COMMENT=	KDE character selector
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kbookmarks/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
