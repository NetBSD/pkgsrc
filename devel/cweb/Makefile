# $NetBSD: Makefile,v 1.22 2005/11/08 18:45:24 tonio Exp $
#
# XXX This package needs to be installed with the same PREFIX as teTeX
#

DISTNAME=		cweb-3.64
PKGREVISION=		2
CATEGORIES=		devel lang
MASTER_SITES=		${MASTER_SITE_TEX_CTAN:=web/cweb/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-cs-faculty.stanford.edu/~knuth/cweb.html
COMMENT=		CWEB System of Structured Documentation

CONFLICTS+=		teTeX-bin>=2.0		# Part of teTeX>=2.0

LATEX_ACCEPTED=		teTeX1

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin man/man1

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

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
