# $NetBSD: Makefile,v 1.3 2008/11/04 08:36:34 adam Exp $

.include "../../games/crossfire-client/Makefile.common"

PKGNAME=	crossfire-client-gtk2-${CROSSFIRE_VERSION}
COMMENT=	Multi-player graphical arcade and adventure game; GTK2 client

INSTALL_DIRS=	gtk-v2

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
