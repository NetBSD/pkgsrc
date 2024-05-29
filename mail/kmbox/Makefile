# $NetBSD: Makefile,v 1.27 2024/05/29 16:33:21 adam Exp $

DISTNAME=	kmbox-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for accessing mail storages in MBox format
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
