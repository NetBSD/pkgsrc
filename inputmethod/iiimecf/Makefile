# $NetBSD: Makefile,v 1.8 2007/10/29 13:02:50 uebayasi Exp $
#

DISTNAME=	IIIMECF-0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}iiimecf-0.6
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/IIIM/

MAINTAINER=	uebayasi@NetBSD.org
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

.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
