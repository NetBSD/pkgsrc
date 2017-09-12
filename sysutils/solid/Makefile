# $NetBSD: Makefile,v 1.11 2017/09/12 13:52:02 wiz Exp $

DISTNAME=	solid-${KF5VER}
PKGREVISION=	9
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Hardware integration and detection
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	flex bison

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
