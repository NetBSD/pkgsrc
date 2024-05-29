# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:33 adam Exp $

DISTNAME=	kdialog-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE utility for displaying dialog boxes from shell scripts
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
