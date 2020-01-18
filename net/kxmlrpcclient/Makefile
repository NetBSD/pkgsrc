# $NetBSD: Makefile,v 1.30 2020/01/18 21:48:19 jperkin Exp $

DISTNAME=	kxmlrpcclient-${KF5VER}
PKGREVISION=	1
CATEGORIES=	net

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	XML-RPC client library for KDE
LICENSE=	2-clause-bsd AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
