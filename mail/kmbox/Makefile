# $NetBSD: Makefile,v 1.28 2024/11/01 00:52:34 wiz Exp $

DISTNAME=	kmbox-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for accessing mail storages in MBox format
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
