# $NetBSD: Makefile,v 1.13 2025/02/12 06:45:16 ryoon Exp $

DISTNAME=	mailimporter-${KAPPSVER}
PKGREVISION=	7
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
