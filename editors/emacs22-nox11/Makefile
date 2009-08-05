# $NetBSD: Makefile,v 1.1.1.1 2009/08/05 10:32:54 minskim Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# Mirror PKG_DESTDIR_SUPPORT setting from emacs/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs22/Makefile"
