# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:37 joerg Exp $

PKGNAME=		sqsh-motif-2.1
PKGREVISION=		4

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-x11-[0-9]*

CONFIGURE_ARGS+=	--with-motif

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../mk/motif.buildlink3.mk"

.include "../../databases/sqsh/Makefile.common"
