# $NetBSD: Makefile,v 1.15 2008/04/24 15:20:06 jlam Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	vi clone with regex-search, hex-edit, HTML/LaTeX preview (X11)

FILESDIR=	${.CURDIR}/../../editors/elvis/files
PATCHDIR=	${.CURDIR}/../../editors/elvis/patches
PKGDIR=		${.CURDIR}/../../editors/elvis

# Mirror PKG_DESTDIR_SUPPORT setting from elvis/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.elvis+=	x11

.include "../../editors/elvis/Makefile"
