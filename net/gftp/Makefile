# $NetBSD: Makefile,v 1.14 2003/12/13 00:45:25 wiz Exp $
#

.include "${.CURDIR}/Makefile.common"
PKGREVISION=	1

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
