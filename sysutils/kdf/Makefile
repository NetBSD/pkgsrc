# $NetBSD: Makefile,v 1.52 2016/03/05 11:29:30 jperkin Exp $

DISTNAME=	kdf-15.12.0
PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Show mount points and disk usage under KDE desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
