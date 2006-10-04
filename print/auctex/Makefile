# $NetBSD: Makefile,v 1.31 2006/10/04 21:56:34 wiz Exp $

DISTNAME=		auctex-11.83
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

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
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
