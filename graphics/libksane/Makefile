# $NetBSD: Makefile,v 1.67 2022/08/11 05:08:44 gutteridge Exp $

DISTNAME=	libksane-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	SANE Library interface for KDE
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
