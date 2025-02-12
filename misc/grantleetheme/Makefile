# $NetBSD: Makefile,v 1.13 2025/02/12 06:45:19 ryoon Exp $

DISTNAME=	grantleetheme-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Library for Grantlee theming support
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
