# $NetBSD: Makefile,v 1.23 2019/07/01 04:08:04 ryoon Exp $

DISTNAME=	kapptemplate-${_KDE_VERSION}
PKGREVISION=	13
CATEGORIES=	devel
COMMENT=	KDE Template Generator

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake tar

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
