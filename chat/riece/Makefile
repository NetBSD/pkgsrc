# $NetBSD: Makefile,v 1.1.1.1 2004/11/30 08:18:39 uebayasi Exp $
#

DISTNAME=	riece-1.0.5
CATEGORIES=	chat japanese
MASTER_SITES=	http://wiliki.designflaw.org/riece/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

USE_NEW_EMACS_MK= \
		YES

EMACS_VERSIONS_ACCEPTED= \
		emacs21 emacs21nox xemacs214

.include "../../mk/emacs.mk"

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
