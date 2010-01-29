# $NetBSD: Makefile,v 1.27 2010/01/29 19:46:20 joerg Exp $
#
PKGNAME=		jed-0.99.16
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../editors/jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations

CONFLICTS=		xjed-[0-9]*

CONFIGURE_ARGS+=	--without-X

.include "../../mk/bsd.pkg.mk"
