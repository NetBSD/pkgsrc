# $NetBSD: Makefile,v 1.28 2006/03/04 21:30:28 jlam Exp $

DISTNAME=		auctex-11.82
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

.include "../../mk/emacs.mk"

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp||}
.endif
CONFIGURE_ARGS+=	--disable-preview

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}

LISPDIR=		${EMACS_LISPPREFIX}
INFO_FILES=	auctex.info

PLIST_SUBST+=		INFODIR=${INFODIR:Q}
MESSAGE_SUBST+=		LISPDIR=${LISPDIR:Q}

.include "../../mk/bsd.pkg.mk"
