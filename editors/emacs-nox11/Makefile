# $NetBSD: Makefile,v 1.20 2006/02/05 23:08:55 joerg Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGNAME=	emacs-nox11-${EMACSVERSION}a
PKGREVISION=	2
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=--without-x

.include "../../mk/bsd.pkg.mk"
