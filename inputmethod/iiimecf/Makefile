# $NetBSD: Makefile,v 1.1.1.1 2002/09/15 07:01:14 uebayasi Exp $
#

DISTNAME=	IIIMECF-0.6
PKGNAME=	iiimecf-0.6
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/IIICF/

MAINTAINER=	uebayasi@netbsd.org
#HOMEPAGE=
COMMENT=	Emacs Lisp library for IIIM Protocol

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
