# $NetBSD: Makefile,v 1.9 2006/05/30 00:26:15 uebayasi Exp $
#

DISTNAME=	riece-3.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat japanese
MASTER_SITES=	http://savannah.nongnu.org/download/riece/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

EMACS_VERSIONS_ACCEPTED= \
		emacs21 emacs21nox xemacs214

WRKSRC=		${WRKDIR}/${DISTNAME:C|[^0-9]$||}

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST
EMACS_MODULES=	base

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=	--with-emacs=${EMACS_BIN:Q}
.elif ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-xemacs=${EMACS_BIN:Q}
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}
.endif
# Riece digs sub directory.
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX:Q}

.include "../../mk/bsd.pkg.mk"
