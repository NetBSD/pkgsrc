# $NetBSD: Makefile,v 1.20 2012/10/03 11:43:38 asau Exp $

DISTNAME=	Mule-UCS-0.84
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	http://unit.aist.go.jp/itri/itri-gist/ftp.m17n.org/pub/mule/Mule-UCS/

MAINTAINER=	uebayasi@NetBSD.org
#HOMEPAGE=
COMMENT=	Another encoding conversion mechanism for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/mule-ucs \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/mule-ucs/big5conv \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/mule-ucs/jisx0213 \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/mule-ucs/reldata

# Mule 4.1 feature required by Mule-UCS was added to 20.7nb1.
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
BUILDLINK_API_DEPENDS.emacs20+=	emacs>=20.7nb1

MESSAGE_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

do-build:
	@cd ${WRKSRC}; \
	${EMACS_BIN} -q --no-site-file -batch -l mucs-comp.el
	@cd ${WRKSRC}/lisp/big5conv; \
	${EMACS_BIN} -q --no-site-file -batch -l big5-comp.el
	@cd ${WRKSRC}/lisp/jisx0213; \
	${EMACS_BIN} -q --no-site-file -batch -l x0213-comp.el

do-install:
	cd ${WRKSRC}/lisp && \
	for f in ChangeLog README* *.txt *.el *.elc *.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${EMACS_LISPPREFIX}/mule-ucs; \
	done
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/* \
	    ${DESTDIR}${EMACS_LISPPREFIX}/mule-ucs/big5conv; \
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/* \
	    ${DESTDIR}${EMACS_LISPPREFIX}/mule-ucs/jisx0213; \
	${INSTALL_DATA} ${WRKSRC}/lisp/reldata/* \
	    ${DESTDIR}${EMACS_LISPPREFIX}/mule-ucs/reldata

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
