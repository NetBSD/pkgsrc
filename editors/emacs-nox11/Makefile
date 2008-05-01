# $NetBSD: Makefile,v 1.27.6.1 2008/05/01 13:41:33 rtr Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/emacs/files
PATCHDIR=	${.CURDIR}/../../editors/emacs/patches
PKGDIR=		${.CURDIR}/../../editors/emacs

# Mirror PKG_DESTDIR_SUPPORT setting from emacs/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs/Makefile"
