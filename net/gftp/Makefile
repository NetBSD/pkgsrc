# $NetBSD: Makefile,v 1.17 2004/03/08 19:40:41 jmmv Exp $
#

.include "${.CURDIR}/Makefile.common"
PKGREVISION=	3

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.5:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
