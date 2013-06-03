# $NetBSD: Makefile,v 1.4 2013/06/03 10:05:42 wiz Exp $

DISTNAME=	kscd-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	multimedia
COMMENT=	KDE CD player

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libmusicbrainz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
