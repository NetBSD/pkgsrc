# $NetBSD: Makefile,v 1.10 2001/05/17 08:38:43 abs Exp $
#
# XXX This package needs to be installed with the same PREFIX as teTeX
#

DISTNAME=		cweb-3.63
CATEGORIES=		devel lang
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=web/cweb/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-cs-faculty.stanford.edu/~knuth/cweb.html
COMMENT=		CWEB System of Structured Documentation

DEPENDS+= 		teTeX-[0-9]*:../../print/teTeX

NO_WRKSUBDIR=		# defined
WRKSRC=			${WRKDIR}

post-patch:
	${MV} ${WRKSRC}/cweb.1 ${WRKSRC}/cweb.1.dist
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${WRKSRC}/cweb.1.dist 	\
	> ${WRKSRC}/cweb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cweave ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ctangle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cweb.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/cwebmac.tex 				\
		${PREFIX}/share/texmf/tex/plain/base
	${INSTALL_DATA_DIR} ${PREFIX}/share/cweb
	${INSTALL_DATA} ${WRKSRC}/c++lib.w ${PREFIX}/share/cweb
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cweb
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/cweb/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cweb
	cd ${WRKSRC} && ${INSTALL_DATA} cwebman.dvi cweave.dvi 		\
		ctangle.dvi ${PREFIX}/share/doc/cweb/
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/cweb.el ${PREFIX}/share/emacs/site-lisp

post-install:
	${PREFIX}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
