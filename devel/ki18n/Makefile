# $NetBSD: Makefile,v 1.11 2017/09/08 02:38:38 ryoon Exp $

DISTNAME=	ki18n-${KF5VER}
PKGREVISION=	7
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced internationalization framework
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
