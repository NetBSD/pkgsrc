# $NetBSD: Makefile,v 1.17 2013/04/06 03:45:12 rodent Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	Clone of vi with regex-search, hex-edit, HTML/LaTeX preview (X11)

FILESDIR=	${.CURDIR}/../../editors/elvis/files
PATCHDIR=	${.CURDIR}/../../editors/elvis/patches
PKGDIR=		${.CURDIR}/../../editors/elvis

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.elvis+=	x11

.include "../../editors/elvis/Makefile"
