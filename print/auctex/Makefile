# $NetBSD: Makefile,v 1.32 2007/01/17 13:18:42 tonio Exp $

DISTNAME=		auctex-11.84
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=auctex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

EMACS_MODULES=		base

.include "../../mk/emacs.mk"

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp||}
.endif
CONFIGURE_ARGS+=	--disable-preview

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

.include "../../mk/bsd.pkg.mk"
