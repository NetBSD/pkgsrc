# $NetBSD: Makefile,v 1.3 2003/03/14 01:26:40 uebayasi Exp $

DISTNAME=	Mule-UCS-0.84
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/Mule-UCS/

MAINTAINER=	uebayasi@netbsd.org
#HOMEPAGE=	
COMMENT=	another encoding conversion mechanism for Emacs

# XXX Emacs 20.7 needs a patch to use Mule UCS.
EMACS_VERSIONS_ACCEPTED=	emacs21

do-build:
	@cd ${WRKSRC}; \
	${EMACS_BIN} -q --no-site-file -batch -l mucs-comp.el
	@cd ${WRKSRC}/lisp/big5conv; \
	${EMACS_BIN} -q --no-site-file -batch -l big5-comp.el
	@cd ${WRKSRC}/lisp/jisx0213; \
	${EMACS_BIN} -q --no-site-file -batch -l x0213-comp.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs
	for f in ChangeLog README* *.txt *.el *.elc *.txt; do \
		${INSTALL_DATA} ${WRKSRC}/lisp/$$f \
		    ${EMACS_LISPPREFIX}/mule-ucs; \
	done
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/big5conv
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/big5conv; \
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/jisx0213
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/jisx0213; \
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs/reldata
	${INSTALL_DATA} ${WRKSRC}/lisp/reldata/* \
	    ${EMACS_LISPPREFIX}/mule-ucs/reldata; \
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
