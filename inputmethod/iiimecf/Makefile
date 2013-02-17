# $NetBSD: Makefile,v 1.15 2013/02/17 19:18:04 dholland Exp $
#

DISTNAME=	IIIMECF-0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}iiimecf-0.6
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://unit.aist.go.jp/itri/itri-gist/ftp.m17n.org/pub/mule/IIIM/

MAINTAINER=	uebayasi@NetBSD.org
#HOMEPAGE=
COMMENT=	Emacs Lisp library for IIIM Protocol

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
EMACS_BUILDLINK=# defined

do-build:
	@cd ${WRKSRC} && \
		${EMACS_BIN} -q --no-site-file -batch -l iiimcf-comp.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/iiimecf
	@for f in ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc; do \
		${INSTALL_DATA} $$f ${DESTDIR}${EMACS_LISPPREFIX}/iiimecf; \
	done

.include "../../editors/emacs/modules.mk"

.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
