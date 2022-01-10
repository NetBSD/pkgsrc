# $NetBSD: Makefile,v 1.58 2022/01/10 01:46:39 ryoon Exp $

DISTNAME=	kremotecontrol-16.12.0
PKGREVISION=	24
CATEGORIES=	misc
COMMENT=	KDE frontend for your remote controls
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
