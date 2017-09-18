# $NetBSD: Makefile,v 1.6 2017/09/18 09:52:56 maya Exp $

DISTNAME=	karchive-${KF5VER}
PKGREVISION=	5
CATEGORIES=	archivers

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt 5 addon providing access to numerous types of archives
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
