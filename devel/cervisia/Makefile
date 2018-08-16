# $NetBSD: Makefile,v 1.40 2018/08/16 18:54:40 adam Exp $

DISTNAME=	cervisia-16.04.0
PKGREVISION=	6
CATEGORIES=	devel
COMMENT=	CVS frontend
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.04.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
