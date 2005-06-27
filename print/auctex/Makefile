# $NetBSD: Makefile,v 1.20 2005/06/27 10:03:54 wiz Exp $

DISTNAME=		auctex-11.55
CATEGORIES=		print
MASTER_SITES=		http://ftp.gnu.org/pub/gnu/auctex/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		YES

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

MAKEFLAGS+=		EMACS=${EMACS_BIN}

LISPDIR=		${EMACS_LISPPREFIX}
INFO_FILES=	auctex.info

PLIST_SUBST+=		INFODIR=${INFODIR}
MESSAGE_SUBST+=		LISPDIR=${LISPDIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
