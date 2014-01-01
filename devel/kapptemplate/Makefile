# $NetBSD: Makefile,v 1.2 2014/01/01 11:52:12 wiz Exp $

DISTNAME=	kapptemplate-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	KDE Template Generator

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
