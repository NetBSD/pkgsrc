# $NetBSD: Makefile,v 1.4 2009/08/26 19:57:29 sno Exp $

.include "../../games/crossfire-client/Makefile.common"

PKGNAME=	crossfire-client-gtk2-${CROSSFIRE_VERSION}
PKGREVISION=	1
COMMENT=	Multi-player graphical arcade and adventure game; GTK2 client

INSTALL_DIRS=	gtk-v2

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
