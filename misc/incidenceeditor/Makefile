# $NetBSD: Makefile,v 1.13 2025/02/12 06:45:19 ryoon Exp $

DISTNAME=	incidenceeditor-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM incidence editor
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
