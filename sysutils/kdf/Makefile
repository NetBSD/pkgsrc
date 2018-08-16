# $NetBSD: Makefile,v 1.61 2018/08/16 18:55:11 adam Exp $

DISTNAME=	kdf-16.04.0
PKGREVISION=	6
CATEGORIES=	sysutils
COMMENT=	Show mount points and disk usage under KDE desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.04.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
