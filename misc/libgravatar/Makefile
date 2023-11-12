# $NetBSD: Makefile,v 1.4 2023/11/12 13:22:50 wiz Exp $

DISTNAME=	libgravatar-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing Gravatar support
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
