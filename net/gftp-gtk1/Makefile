# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:47 wiz Exp $

.include "${.CURDIR}/../gftp/Makefile.common"

PKGNAME=	gftp-gtk1-${VERSION}
PKGREVISION=	1
COMMENT=	Multithreaded GTK+ ftp client

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs
CONFLICTS=	gftp-[0-9]*

CONFIGURE_ARGS+=	--disable-gtk20

PLIST_SRC=	${.CURDIR}/../gftp/PLIST
DISTINFO_FILE=	${.CURDIR}/../gftp/distinfo

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
