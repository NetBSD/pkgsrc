# $NetBSD: Makefile,v 1.4 2012/06/14 07:44:37 sbd Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	2

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror pre-bsd.prefs.mk settings from emacs/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir
SETGIDGAME=		yes

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
