# $NetBSD: Makefile,v 1.2 2009/10/07 10:50:59 obache Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	1

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror PKG_DESTDIR_SUPPORT setting from emacs/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
