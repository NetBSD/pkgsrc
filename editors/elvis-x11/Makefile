# $NetBSD: Makefile,v 1.16 2012/10/03 11:43:32 asau Exp $

PKGNAME=	${PKGNAME_BASE:S/-/-x11-/}
COMMENT=	vi clone with regex-search, hex-edit, HTML/LaTeX preview (X11)

FILESDIR=	${.CURDIR}/../../editors/elvis/files
PATCHDIR=	${.CURDIR}/../../editors/elvis/patches
PKGDIR=		${.CURDIR}/../../editors/elvis

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.elvis+=	x11

.include "../../editors/elvis/Makefile"
