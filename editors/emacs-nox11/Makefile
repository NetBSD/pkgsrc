# $NetBSD: Makefile,v 1.25 2007/01/25 21:00:05 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	8
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=--without-x

.include "../../mk/bsd.pkg.mk"
