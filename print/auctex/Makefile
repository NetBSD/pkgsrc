# $NetBSD: Makefile,v 1.22 2005/10/15 20:09:35 tonio Exp $

DISTNAME=		auctex-11.81
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

.include "../../mk/emacs.mk"
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		YES

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp||}
.endif

MAKEFLAGS+=		EMACS=${EMACS_BIN}

LISPDIR=		${EMACS_LISPPREFIX}
INFO_FILES=	auctex.info preview-latex.info

PLIST_SUBST+=		INFODIR=${INFODIR}
MESSAGE_SUBST+=		LISPDIR=${LISPDIR}

.include "../../mk/bsd.pkg.mk"
