# $NetBSD: Makefile,v 1.2 2005/03/05 09:14:11 uebayasi Exp $
#

DISTNAME=	riece-1.0.7a
CATEGORIES=	chat japanese
MASTER_SITES=	http://savannah.nongnu.org/download/riece/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

EMACS_VERSIONS_ACCEPTED= \
		emacs21 emacs21nox xemacs214

.include "../../mk/emacs.mk"

WRKSRC=		${WRKDIR}/${DISTNAME:C|[^0-9]$||}

GNU_CONFIGURE=	YES
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
.elif ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-xemacs=${EMACS_BIN}
CONFIGURE_ARGS+=--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}
.elif ${EMACS_FLAVOR} == "xemacs"
.endif
# Riece digs sub directory.
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}

INFO_FILES=	riece-ja.info

.include "../../mk/bsd.pkg.mk"
