# $NetBSD: Makefile,v 1.68 2026/05/14 16:40:45 ryoon Exp $

DISTNAME=	libkomparediff2-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kompare/
COMMENT=	Library to compare files and strings
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
