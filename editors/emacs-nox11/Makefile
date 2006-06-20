# $NetBSD: Makefile,v 1.23 2006/06/20 23:47:24 minskim Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	5
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=--without-x

.include "../../mk/bsd.pkg.mk"
