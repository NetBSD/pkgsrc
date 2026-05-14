# $NetBSD: Makefile,v 1.96 2026/05/14 16:41:14 ryoon Exp $

DISTNAME=	libksane-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	SANE Library interface for KDE
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../graphics/ksanecore/buildlink3.mk"
.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
