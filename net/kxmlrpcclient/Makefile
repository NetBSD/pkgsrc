# $NetBSD: Makefile,v 1.6 2017/02/06 13:54:48 wiz Exp $

DISTNAME=	kxmlrpcclient-${KF5VER}
PKGREVISION=	3
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	XML-RPC client library for KDE
LICENSE=	2-clause-bsd AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
