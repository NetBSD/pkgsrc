# $NetBSD: Makefile,v 1.11 2024/11/01 12:53:29 wiz Exp $

DISTNAME=	eventviews-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Library for creating events
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/kdiagram/buildlink3.mk"
.include "../../time/calendarsupport/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
