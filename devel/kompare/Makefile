# $NetBSD: Makefile,v 1.25 2018/08/16 18:54:41 adam Exp $

DISTNAME=	kompare-${_KDE_VERSION}
PKGREVISION=	12
CATEGORIES=	devel
COMMENT=	Diff/Patch Frontend

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libkomparediff2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
