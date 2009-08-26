# $NetBSD: Makefile,v 1.18 2009/08/26 19:57:24 sno Exp $
#

DISTNAME=	leafpad-0.8.4
PKGREVISION=	5
CATEGORIES=	editors gnome
MASTER_SITES=	http://savannah.nongnu.org/download/leafpad/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tarot.freeshell.org/leafpad/
COMMENT=	Simple and light text editor using GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
