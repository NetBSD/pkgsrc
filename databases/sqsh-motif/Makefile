# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:23 tv Exp $

PKGNAME=		sqsh-motif-2.1
PKGREVISION=	1

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-x11-[0-9]*

CONFIGURE_ARGS+=	--with-motif

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../mk/motif.buildlink3.mk"

.include "../../databases/sqsh/Makefile.common"
