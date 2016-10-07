# $NetBSD: Makefile,v 1.31 2016/10/07 18:26:01 adam Exp $

DISTNAME=	kmag-15.12.0
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	KDE screen magnifier
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
