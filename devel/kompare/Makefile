# $NetBSD: Makefile,v 1.20 2017/04/30 01:21:33 ryoon Exp $

DISTNAME=	kompare-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	devel
COMMENT=	Diff/Patch Frontend

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libkomparediff2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
