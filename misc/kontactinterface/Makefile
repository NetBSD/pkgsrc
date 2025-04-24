# $NetBSD: Makefile,v 1.15 2025/04/24 14:15:09 wiz Exp $

DISTNAME=	kontactinterface-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Kontact Plugin Interface Library
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
