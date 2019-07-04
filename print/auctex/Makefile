# $NetBSD: Makefile,v 1.44 2019/07/04 15:06:06 hauke Exp $

DISTNAME=		auctex-11.89
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=auctex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs
LICENSE=		gnu-gpl-v3

INSTALLATION_DIRS=	share/doc/auctex
INSTALLATION_DIRS+=	${EMACS_INFOPREFIX}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/auctex

BUILD_DEFS+=		VARBASE

EMACS_MODULES=		base

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}
CONFIGURE_ARGS+=	--disable-preview
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}

# We are not building an XEmacs package!
CONFIGURE_ARGS.xemacs=	--without-packagedir
CONFIGURE_ARGS.xemacs+=	--with-lispdir=${EMACS_LISPPREFIX}

MAKE_DIRS_PERMS+=	${VARBASE}/auctex ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
