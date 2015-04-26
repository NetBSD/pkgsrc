# $NetBSD: Makefile,v 1.11 2015/04/26 05:54:30 mef Exp $

PKGNAME=	emacs21-nox11-${EMACSVERSION}a
PKGREVISION=	13
CATEGORIES=	editors
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs21-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Forcibly remove any "x11" options.
PKG_OPTIONS.emacs+=	-x11 -xaw3d -motif -xaw

.include "../../editors/emacs21/options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
