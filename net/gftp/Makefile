# $NetBSD: Makefile,v 1.16 2004/03/08 10:11:17 tron Exp $
#

.include "${.CURDIR}/Makefile.common"
PKGREVISION=	2

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
