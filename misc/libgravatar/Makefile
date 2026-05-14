# $NetBSD: Makefile,v 1.20 2026/05/14 16:41:34 ryoon Exp $

DISTNAME=	libgravatar-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing Gravatar support
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
