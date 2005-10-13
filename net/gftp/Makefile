# $NetBSD: Makefile,v 1.21 2005/10/13 16:44:59 wiz Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client
PKGREVISION=	1

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
