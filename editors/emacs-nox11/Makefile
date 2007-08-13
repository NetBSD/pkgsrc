# $NetBSD: Makefile,v 1.27 2007/08/13 12:40:57 jlam Exp $

PKGNAME=	emacs-nox11-${EMACSVERSION}
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Forcibly remove any "x11" options.
PKG_OPTIONS.emacs+=	-x11 -gtk -motif -xaw

.include "../../editors/emacs/Makefile"
