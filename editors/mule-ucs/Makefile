# $NetBSD: Makefile,v 1.1.1.1 2002/09/15 06:07:03 uebayasi Exp $

DISTNAME=	Mule-UCS-0.84
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/Mule-UCS/

MAINTAINER=	uebayasi@netbsd.org
#HOMEPAGE=	
COMMENT=	another encoding conversion mechanism for Emacs

# XXX Emacs 20.7 needs a patch to use Mule UCS.
EMACS_VERSIONS_ACCEPTED=	emacs21

do-build:
	@cd ${WRKSRC}; \
	for f in lisp/*.el; do \
		${EMACS_BIN} -q --no-site-file -batch -l mucs-comp.el $$f; \
	done

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/mule-ucs
	@for f in ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc; do \
		${INSTALL_DATA} $$f ${EMACS_LISPPREFIX}/mule-ucs; \
	done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
