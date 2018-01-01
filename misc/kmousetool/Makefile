# $NetBSD: Makefile,v 1.36 2018/01/01 21:18:43 adam Exp $

DISTNAME=	kmousetool-16.12.0
PKGREVISION=	3
CATEGORIES=	misc
COMMENT=	KDE mouse manipulation tool
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
