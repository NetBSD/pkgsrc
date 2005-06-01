# $NetBSD: Makefile,v 1.3 2005/06/01 18:02:42 jlam Exp $

PKGNAME=		sqsh-x11-2.1
COMMENT=		SQL shell for Sybase and MS-SQL servers (X11 support)

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-motif-[0-9]*

CONFIGURE_ARGS+=	--with-x

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../mk/x11.buildlink3.mk"
.include "../../databases/sqsh/Makefile.common"
