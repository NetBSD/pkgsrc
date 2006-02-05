# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:26 joerg Exp $
#

DISTNAME=	riece-2.0.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
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
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN:Q}
.elif ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-xemacs=${EMACS_BIN:Q}
CONFIGURE_ARGS+=--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}
.elif ${EMACS_FLAVOR} == "xemacs"
.endif
# Riece digs sub directory.
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX:Q}

INFO_FILES=	riece-ja.info

.include "../../mk/bsd.pkg.mk"
