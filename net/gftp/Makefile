# $NetBSD: Makefile,v 1.13 2003/09/01 21:38:43 xtraeme Exp $
#

.include "${.CURDIR}/Makefile.common"

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
