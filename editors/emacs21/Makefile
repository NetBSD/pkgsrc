# $NetBSD: Makefile,v 1.21 2012/06/14 07:44:37 sbd Exp $

PKGREVISION=	23
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

CONFLICTS+=	emacs-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	imake

.include "options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
