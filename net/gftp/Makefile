# $NetBSD: Makefile,v 1.26 2006/06/27 20:11:12 joerg Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client
PKGREVISION=	5

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
