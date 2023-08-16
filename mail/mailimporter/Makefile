# $NetBSD: Makefile,v 1.1 2023/08/16 05:31:35 markd Exp $

DISTNAME=	mailimporter-${KAPPSVER}
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
