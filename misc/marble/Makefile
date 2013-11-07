# $NetBSD: Makefile,v 1.19 2013/11/07 12:35:41 markd Exp $

DISTNAME=	marble-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	KDE desktop globe

MAKE_JOBS_SAFE=	NO

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
