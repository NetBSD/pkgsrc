# $NetBSD: Makefile,v 1.2 2024/05/29 16:31:17 adam Exp $

DISTNAME=	karchive-${KF6VER}
PKGREVISION=	1
CATEGORIES=	archivers

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt 6 addon providing access to numerous types of archives
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
