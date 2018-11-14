# $NetBSD: Makefile,v 1.44 2018/11/14 22:21:29 kleink Exp $

.include "../../games/crossfire-client/Makefile.common"

PKGNAME=	crossfire-client-gtk2-${CROSSFIRE_VERSION}
PKGREVISION=	41
COMMENT=	Multi-player graphical arcade and adventure game; GTK2 client

INSTALL_DIRS=	gtk-v2

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
