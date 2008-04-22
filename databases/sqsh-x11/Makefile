# $NetBSD: Makefile,v 1.7 2008/04/22 16:23:37 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Athena GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

PKG_OPTIONS.sqsh+=	-sqsh-motif sqsh-xaw

.include "../../databases/sqsh/Makefile"
