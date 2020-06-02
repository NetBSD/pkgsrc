# $NetBSD: Makefile,v 1.48 2020/06/02 08:24:22 adam Exp $

DISTNAME=	sweeper-16.12.0
PKGREVISION=	15
CATEGORIES=	sysutils
COMMENT=	KDE system cleaner
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
