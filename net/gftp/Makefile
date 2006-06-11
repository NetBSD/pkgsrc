# $NetBSD: Makefile,v 1.25 2006/06/11 13:56:41 joerg Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client
PKGREVISION=	4

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
