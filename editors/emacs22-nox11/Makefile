# $NetBSD: Makefile,v 1.7 2013/02/17 00:40:40 dholland Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs22/:S/-/-nox11-/}
PKGREVISION=	3

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror pre-bsd.prefs.mk settings from emacs/Makefile.
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
