# $NetBSD: Makefile,v 1.33 2007/10/29 04:44:04 uebayasi Exp $

DISTNAME=		auctex-11.84
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=auctex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

EMACS_MODULES=		base

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}
CONFIGURE_ARGS+=	--disable-preview

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp||}

.include "../../mk/emacs.mk"

.include "../../mk/bsd.pkg.mk"
