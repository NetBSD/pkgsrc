# $NetBSD: Makefile,v 1.11 2024/11/01 12:53:33 wiz Exp $

DISTNAME=	kdialog-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE utility for displaying dialog boxes from shell scripts
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
