# $NetBSD: Makefile,v 1.29 2006/04/06 03:32:50 jlam Exp $

DISTNAME=		auctex-11.82
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		3
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
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
