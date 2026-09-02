# $NetBSD: Makefile,v 1.24 2026/09/02 19:03:32 wiz Exp $

DISTNAME=	kontactinterface-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Kontact Plugin Interface Library
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
