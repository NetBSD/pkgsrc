# $NetBSD: Makefile,v 1.15 2004/01/03 18:49:47 reed Exp $
#

.include "${.CURDIR}/Makefile.common"
PKGREVISION=	2

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
