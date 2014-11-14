# $NetBSD: Makefile,v 1.10 2014/11/14 08:03:30 markd Exp $

DISTNAME=	kapptemplate-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	KDE Template Generator

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake tar

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
