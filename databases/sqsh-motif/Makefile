# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 12:50:04 grant Exp $

PKGNAME=		sqsh-motif-2.1

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-x11-[0-9]*

CONFIGURE_ARGS+=	--with-motif

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../mk/motif.buildlink2.mk"

.include "../../databases/sqsh/Makefile.common"
