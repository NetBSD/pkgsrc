# $NetBSD: Makefile,v 1.24 2018/01/01 21:18:26 adam Exp $

DISTNAME=	katomic-${_KDE_VERSION}
PKGREVISION=	8
CATEGORIES=	games
COMMENT=	Build complex atoms with a minimal amount of moves

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PERL+=	katomic-levelset-upd.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
