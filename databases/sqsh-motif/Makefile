# $NetBSD: Makefile,v 1.2 2004/05/03 22:46:56 wiz Exp $

PKGNAME=		sqsh-motif-2.1

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-x11-[0-9]*

CONFIGURE_ARGS+=	--with-motif

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../mk/motif.buildlink3.mk"

.include "../../databases/sqsh/Makefile.common"
