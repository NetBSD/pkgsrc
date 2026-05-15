# $NetBSD: Makefile,v 1.82 2026/05/15 09:58:57 adam Exp $

DISTNAME=	sweeper-16.12.0
PKGREVISION=	48
CATEGORIES=	misc sysutils
COMMENT=	KDE system cleaner
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
