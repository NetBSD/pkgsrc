# $NetBSD: Makefile,v 1.8 2011/03/21 06:05:44 obache Exp $

PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	13
CATEGORIES=	editors
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

# Forcibly remove any "x11" options.
PKG_OPTIONS.emacs+=	-x11 -emacs-xaw3d -motif -xaw

.include "../../editors/emacs21/options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
