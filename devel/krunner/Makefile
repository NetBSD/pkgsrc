# $NetBSD: Makefile,v 1.8 2017/04/22 21:03:10 adam Exp $

DISTNAME=	krunner-${KF5VER}
PKGREVISION=	7
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Framework for providing different actions given a string query
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
