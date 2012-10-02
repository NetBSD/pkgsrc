# $NetBSD: Makefile,v 1.10 2012/10/02 21:25:54 asau Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-motif-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Motif GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.sqsh+=	sqsh-motif -sqsh-xaw

.include "../../databases/sqsh/Makefile"
