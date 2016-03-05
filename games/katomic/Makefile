# $NetBSD: Makefile,v 1.19 2016/03/05 11:28:32 jperkin Exp $

DISTNAME=	katomic-${_KDE_VERSION}
PKGREVISION=	3
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
