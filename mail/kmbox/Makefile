# $NetBSD: Makefile,v 1.38 2026/09/02 19:03:17 wiz Exp $

DISTNAME=	kmbox-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for accessing mail storages in MBox format
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
