# $NetBSD: Makefile,v 1.6 2012/12/27 17:50:26 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	3

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror pre-bsd.prefs.mk settings from emacs/Makefile.
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
