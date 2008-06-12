# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:30 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/crossfire-client/Makefile.common"

PKGNAME=	crossfire-client-gtk2-${CROSSFIRE_VERSION}
COMMENT=	Multi-player graphical arcade and adventure game; GTK2 client

INSTALL_DIRS=	gtk-v2

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
