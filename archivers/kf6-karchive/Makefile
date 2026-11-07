# $NetBSD: Makefile,v 1.19 2026/11/07 19:11:17 wiz Exp $

DISTNAME=	karchive-${KF6VER}
PKGREVISION=	3
CATEGORIES=	archivers

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt 6 addon providing access to numerous types of archives
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		_KDE_build/KF6Archive.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
