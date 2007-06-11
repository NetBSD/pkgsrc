# $NetBSD: Makefile,v 1.26 2007/06/11 13:57:21 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}
PKGNAME=	emacs-nox11-${EMACSVERSION}
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor) - non X11 version

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-[0-9]*

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png

.include "../../mk/bsd.pkg.mk"
