# $NetBSD: Makefile,v 1.42 2024/11/01 12:53:34 wiz Exp $

DISTNAME=	kidentitymanagement-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for managing identitites
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
