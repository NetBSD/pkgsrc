# $NetBSD: Makefile,v 1.11 2024/11/01 12:53:35 wiz Exp $

DISTNAME=	kontactinterface-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Kontact Plugin Interface Library
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
