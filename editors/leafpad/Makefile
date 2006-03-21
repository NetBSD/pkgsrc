# $NetBSD: Makefile,v 1.12 2006/03/21 06:00:45 jlam Exp $
#

DISTNAME=	leafpad-0.8.4
PKGREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	http://savannah.nongnu.org/download/leafpad/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tarot.freeshell.org/leafpad/
COMMENT=	Simple and light text editor using GTK+

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
