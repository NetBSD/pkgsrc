# $NetBSD: Makefile,v 1.14 2025/04/17 21:51:28 wiz Exp $

DISTNAME=	mailimporter-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Mail importer library
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
