# $NetBSD: Makefile,v 1.3 2024/06/15 06:22:40 jperkin Exp $

DISTNAME=	kcoreaddons-${KF6VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_ARGS.SunOS+=	-DENABLE_INOTIFY=OFF
LDFLAGS.SunOS+=		-lsocket

.if ${OPSYS} != "SunOS"
.include "../../devel/libinotify/buildlink3.mk"
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
