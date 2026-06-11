# $NetBSD: Makefile,v 1.23 2026/06/11 07:17:23 wiz Exp $

DISTNAME=	incidenceeditor-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM incidence editor
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/eventviews/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
