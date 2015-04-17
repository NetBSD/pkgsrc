# $NetBSD: Makefile,v 1.28 2015/04/17 15:53:00 adam Exp $

DISTNAME=	cervisia-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	CVS frontend

.include "../../meta-pkgs/kde4/Makefile.kde4"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
