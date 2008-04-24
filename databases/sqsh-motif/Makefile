# $NetBSD: Makefile,v 1.9 2008/04/24 15:20:06 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-motif-/}
COMMENT=	SQL shell for Sybase and MS-SQL servers (Motif GUI)

FILESDIR=	${.CURDIR}/../../databases/sqsh/files
PATCHDIR=	${.CURDIR}/../../databases/sqsh/patches
PKGDIR=		${.CURDIR}/../../databases/sqsh

# Mirror PKG_DESTDIR_SUPPORT setting from sqsh/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.sqsh+=	sqsh-motif -sqsh-xaw

.include "../../databases/sqsh/Makefile"
