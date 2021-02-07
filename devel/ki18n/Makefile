# $NetBSD: Makefile,v 1.41 2021/02/07 06:30:18 ryoon Exp $

DISTNAME=	ki18n-${KF5VER}
PKGREVISION=	5
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced internationalization framework
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
