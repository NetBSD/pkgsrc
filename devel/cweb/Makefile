# $NetBSD: Makefile,v 1.4 2001/02/16 14:38:21 wiz Exp $

DISTNAME=	cweb-3.63
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=web/cweb/}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~knuth/cweb.html
COMMENT=	The CWEB System of Structured Documentation

DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX

NO_WRKSUBDIR=	YES
WRKSRC=		${WRKDIR}

EVAL_PREFIX+=	PREFIX=teTeX

post-patch:
	@for f in ${WRKSRC}/cweb.1 ; do \
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' < $$f > $$f.tmp \
	&& ${MV} $$f.tmp $$f ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cweave ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ctangle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cweb.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/cwebmac.tex \
	${PREFIX}/share/texmf/tex/plain/base
	${INSTALL_DATA_DIR} ${PREFIX}/share/cweb
	${INSTALL_DATA} ${WRKSRC}/c++lib.w ${PREFIX}/share/cweb
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cweb
	@for f in ${WRKSRC}/examples/*; do				\
		i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/cweb/";	\
		${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cweb
	@for f in cwebman.tex cwebman.dvi cweave.dvi ctangle.dvi; do	     \
		j="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/cweb/"; \
		${ECHO} $$j; $$j;					     \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/cweb.el ${PREFIX}/share/emacs/site-lisp

post-install:
	mktexlsr

.include "../../mk/bsd.pkg.mk"
