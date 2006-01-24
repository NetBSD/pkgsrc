# $NetBSD: Makefile,v 1.22 2006/01/24 07:32:29 wiz Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client
PKGREVISION=	2

CONFLICTS=	gftp-gtk1-[0-9]*

USE_DIRS+=	gnome2-1.5

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
