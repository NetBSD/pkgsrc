# $NetBSD: Makefile,v 1.14 2018/01/16 15:20:48 wiz Exp $

PKGNAME=	emacs21-nox11-${EMACSVERSION}a
PKGREVISION=	14
CATEGORIES=	editors
COMMENT_EXTRA=	: non-X11 version

CONFLICTS+=	emacs21-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../editors/emacs21/Makefile.common"
.include "../../mk/bsd.pkg.mk"
