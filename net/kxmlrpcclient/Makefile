# $NetBSD: Makefile,v 1.33 2020/03/10 22:08:57 wiz Exp $

DISTNAME=	kxmlrpcclient-${KF5VER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	XML-RPC client library for KDE
LICENSE=	2-clause-bsd AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
