# $NetBSD: Makefile,v 1.11 2024/11/01 12:53:37 wiz Exp $

DISTNAME=	libgravatar-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing Gravatar support
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
