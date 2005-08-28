# $NetBSD: Makefile,v 1.6 2005/08/28 04:25:29 uebayasi Exp $
#

DISTNAME=	IIIMECF-0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}iiimecf-0.6
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/IIIM/

MAINTAINER=	uebayasi@NetBSD.org
#HOMEPAGE=
COMMENT=	Emacs Lisp library for IIIM Protocol

DEPENDS+=	${EMACS_PKGNAME_PREFIX}Mule-UCS>=0.82:../../editors/mule-ucs

do-build:
	@cd ${WRKSRC} && \
		${EMACS_BIN} -q --no-site-file -batch -l iiimcf-comp.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/iiimecf
	@for f in ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc; do \
		${INSTALL_DATA} $$f ${EMACS_LISPPREFIX}/iiimecf; \
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
