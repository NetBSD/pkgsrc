# $NetBSD: Makefile,v 1.9 2025/04/02 19:30:30 markd Exp $

DISTNAME=	kcoreaddons-${KF6VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf6.mk"

LDFLAGS.SunOS+=		-lsocket

.if ${OPSYS} != "SunOS"
.include "../../devel/libinotify/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_INOTIFY=OFF
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
