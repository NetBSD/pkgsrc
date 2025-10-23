# $NetBSD: Makefile,v 1.16 2025/10/23 20:38:22 wiz Exp $

DISTNAME=	kdialog-${KAPPSVER}
PKGREVISION=	10
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE utility for displaying dialog boxes from shell scripts
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
