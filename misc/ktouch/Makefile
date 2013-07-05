# $NetBSD: Makefile,v 1.17 2013/07/05 13:29:39 ryoon Exp $

DISTNAME=	ktouch-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	misc
COMMENT=	KDE touch typing tutor

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
