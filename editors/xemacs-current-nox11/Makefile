# $NetBSD: Makefile,v 1.2 2008/04/24 21:32:47 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/xemacs-current/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs-current/patches
PKGDIR=		${.CURDIR}/../../editors/xemacs-current

# Mirror PKG_DESTDIR_SUPPORT setting from xemacs-current/Makefile.
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.xemacs+=	-x11 -xft -gtk -lucid -motif

.include "../../editors/xemacs-current/Makefile"
