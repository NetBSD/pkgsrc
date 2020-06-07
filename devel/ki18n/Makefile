# $NetBSD: Makefile,v 1.36 2020/06/07 10:59:23 markd Exp $

DISTNAME=	ki18n-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced internationalization framework
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
