# $NetBSD: Makefile,v 1.70 2023/01/29 21:17:40 ryoon Exp $

DISTNAME=	kgpg-16.08.0
PKGREVISION=	29
CATEGORIES=	security
COMMENT=	KDE encryption tool
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.08.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
