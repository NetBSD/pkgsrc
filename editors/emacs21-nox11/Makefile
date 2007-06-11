# $NetBSD: Makefile,v 1.4 2007/06/11 13:38:47 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	8
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs21/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=--without-x

.include "../../mk/bsd.pkg.mk"
