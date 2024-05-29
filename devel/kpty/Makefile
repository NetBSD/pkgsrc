# $NetBSD: Makefile,v 1.47 2024/05/29 16:32:11 adam Exp $

DISTNAME=	kpty-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Pty abstraction
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	grantpty

.if ${OPSYS} == "SunOS"
PLIST.grantpty=	yes
.endif

.include "../../lang/python/tool.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
