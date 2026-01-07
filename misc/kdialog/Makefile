# $NetBSD: Makefile,v 1.18 2026/01/07 08:47:57 wiz Exp $

DISTNAME=	kdialog-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE utility for displaying dialog boxes from shell scripts
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
