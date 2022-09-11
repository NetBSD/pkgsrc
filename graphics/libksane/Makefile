# $NetBSD: Makefile,v 1.68 2022/09/11 12:51:08 wiz Exp $

DISTNAME=	libksane-${KAPPSVER}
PKGREVISION=	9
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
