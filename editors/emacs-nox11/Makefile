# $NetBSD: Makefile,v 1.19 2005/06/08 14:39:40 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	1
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=--without-x

.include "../../mk/bsd.pkg.mk"
