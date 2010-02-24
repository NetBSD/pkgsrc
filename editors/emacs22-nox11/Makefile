# $NetBSD: Makefile,v 1.3 2010/02/24 13:05:44 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	1

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror pre-bsd.prefs.mk settings from emacs/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
