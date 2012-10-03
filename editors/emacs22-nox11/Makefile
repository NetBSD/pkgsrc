# $NetBSD: Makefile,v 1.5 2012/10/03 11:43:33 asau Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	2

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror pre-bsd.prefs.mk settings from emacs/Makefile.
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
