# $NetBSD: Makefile,v 1.23 2006/02/05 23:10:24 joerg Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client
PKGREVISION=	3

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
