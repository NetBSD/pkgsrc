# $NetBSD: Makefile,v 1.8 2008/04/23 20:23:38 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Athena GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.sqsh+=	-sqsh-motif sqsh-xaw

.include "../../databases/sqsh/Makefile"
