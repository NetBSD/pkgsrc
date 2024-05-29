# $NetBSD: Makefile,v 1.2 2024/05/29 16:32:09 adam Exp $

DISTNAME=	kpty-${KF6VER}
PKGREVISION=	1
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
