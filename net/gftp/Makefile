# $NetBSD: Makefile,v 1.18 2004/03/26 02:27:47 wiz Exp $
#

.include "${.CURDIR}/Makefile.common"
PKGREVISION=	4

COMMENT=	Multithreaded GTK2+ ftp client

DEPENDS+=	gnome2-dirs>=1.5:../../misc/gnome2-dirs

CONFLICTS=	gftp-gtk1-[0-9]*

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
