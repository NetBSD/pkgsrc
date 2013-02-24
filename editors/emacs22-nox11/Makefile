# $NetBSD: Makefile,v 1.9 2013/02/24 01:25:30 dholland Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs22/:S/-/-nox11-/}
PKGREVISION=	4

CONFLICTS+=	emacs22-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# This needs to be set before including bsd.prefs.mk.
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile.common"
