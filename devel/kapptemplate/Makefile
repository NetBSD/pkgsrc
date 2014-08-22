# $NetBSD: Makefile,v 1.7 2014/08/22 11:24:28 wiz Exp $

DISTNAME=	kapptemplate-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	devel
COMMENT=	KDE Template Generator

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
