# $NetBSD: Makefile,v 1.13 2007/10/29 04:38:47 uebayasi Exp $
#

DISTNAME=	riece-4.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat japanese
MASTER_SITES=	http://savannah.nongnu.org/download/riece/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

EMACS_VERSIONS_ACCEPTED= \
		emacs22 emacs22nox emacs21 emacs21nox xemacs214

WRKSRC=		${WRKDIR}/${DISTNAME:C|[^0-9]$||}

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST
EMACS_MODULES=	base

# --with-emacs=... or --with-xemacs=...
CONFIGURE_ARGS+=	--with-${EMACS_FLAVOR}=${EMACS_BIN:Q}
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

# Riece digs sub directory.
CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX:Q}
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}

.include "../../mk/emacs.mk"

.include "../../mk/bsd.pkg.mk"
