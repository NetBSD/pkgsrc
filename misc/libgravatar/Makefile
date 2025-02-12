# $NetBSD: Makefile,v 1.13 2025/02/12 06:45:22 ryoon Exp $

DISTNAME=	libgravatar-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing Gravatar support
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
