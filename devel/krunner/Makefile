# $NetBSD: Makefile,v 1.10 2017/09/12 13:51:59 wiz Exp $

DISTNAME=	krunner-${KF5VER}
PKGREVISION=	9
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
