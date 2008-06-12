# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:30 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/crossfire-client/Makefile.common"

PKGNAME=	crossfire-client-gtk-${CROSSFIRE_VERSION}
COMMENT=	Multi-player graphical arcade and adventure game; GTK client

INSTALL_DIRS=	gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
