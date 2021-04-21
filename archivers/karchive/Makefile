# $NetBSD: Makefile,v 1.33 2021/04/21 11:40:12 adam Exp $

DISTNAME=	karchive-${KF5VER}
PKGREVISION=	1
CATEGORIES=	archivers

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt 5 addon providing access to numerous types of archives
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
