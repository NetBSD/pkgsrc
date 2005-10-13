# $NetBSD: Makefile,v 1.8 2005/10/13 16:44:59 wiz Exp $

.include "${.CURDIR}/../gftp/Makefile.common"

PKGNAME=	gftp-gtk1-${VERSION}
PKGREVISION=	1
COMMENT=	Multithreaded GTK+ ftp client

CONFLICTS=	gftp-[0-9]*

USE_DIRS+=	gnome1-1.0

CONFIGURE_ARGS+=	--disable-gtk20

PATCHDIR=	${.CURDIR}/../gftp/patches
PLIST_SRC=	${.CURDIR}/../gftp/PLIST
DISTINFO_FILE=	${.CURDIR}/../gftp/distinfo

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
