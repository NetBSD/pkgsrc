# $NetBSD: Makefile,v 1.19 2011/03/21 06:05:44 obache Exp $

PKGREVISION=	21
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

CONFLICTS+=	emacs-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	imake

.include "options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
