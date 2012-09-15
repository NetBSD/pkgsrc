# $NetBSD: Makefile,v 1.33 2012/09/15 10:05:00 obache Exp $
#

DISTNAME=		kphotoalbum-3.1.1
PKGREVISION=		16
CATEGORIES=		graphics
MASTER_SITES=		http://ktown.kde.org/kphotoalbum/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/kphotoalbum/
COMMENT=		Image organizer

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		kimdaba-*

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_TOOLS+=		msgfmt pkg-config

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../graphics/libkdcraw-kde3/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
