# $NetBSD: Makefile,v 1.5 2004/04/14 16:15:26 jmmv Exp $

.include "${.CURDIR}/../gftp/Makefile.common"

PKGNAME=	gftp-gtk1-${VERSION}
COMMENT=	Multithreaded GTK+ ftp client

CONFLICTS=	gftp-[0-9]*

USE_DIRS+=	gnome1-1.0

CONFIGURE_ARGS+=	--disable-gtk20

PLIST_SRC=	${.CURDIR}/../gftp/PLIST
DISTINFO_FILE=	${.CURDIR}/../gftp/distinfo

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
