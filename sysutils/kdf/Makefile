# $NetBSD: Makefile,v 1.64 2019/08/22 12:23:46 ryoon Exp $

DISTNAME=	kdf-16.04.0
PKGREVISION=	9
CATEGORIES=	sysutils
COMMENT=	Show mount points and disk usage under KDE desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.04.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
