# $NetBSD: Makefile,v 1.5 2024/01/30 14:22:20 ryoon Exp $

DISTNAME=	kontactinterface-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Kontact Plugin Interface Library
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
