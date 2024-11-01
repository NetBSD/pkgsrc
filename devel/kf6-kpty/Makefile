# $NetBSD: Makefile,v 1.4 2024/11/01 12:52:11 wiz Exp $

DISTNAME=	kpty-${KF6VER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Pty abstraction
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../lang/python/tool.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
