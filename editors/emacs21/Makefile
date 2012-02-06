# $NetBSD: Makefile,v 1.20 2012/02/06 12:40:00 wiz Exp $

PKGREVISION=	22
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

CONFLICTS+=	emacs-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	imake

.include "options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
