# $NetBSD: Makefile,v 1.20 2014/01/01 11:52:11 wiz Exp $

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
