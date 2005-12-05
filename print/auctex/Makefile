# $NetBSD: Makefile,v 1.24 2005/12/05 20:50:52 rillig Exp $

DISTNAME=		auctex-11.81
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

.include "../../mk/emacs.mk"

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes
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
MESSAGE_SUBST+=		LISPDIR=${LISPDIR}

.include "../../mk/bsd.pkg.mk"
