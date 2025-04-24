# $NetBSD: Makefile,v 1.46 2025/04/24 14:15:08 wiz Exp $

DISTNAME=	kidentitymanagement-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for managing identitites
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
