# $NetBSD: Makefile,v 1.1.1.1 2000/11/26 23:35:17 jtb Exp $

DISTNAME=	calc-2.02f
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=calc/}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/calc/calc.html

DEPENDS+=	emacs>=20.0:../../editors/emacs

EVAL_PREFIX+=	PREFIX=emacs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/calc
	@(cd ${WRKSRC}; for i in *.el *.elc calccard.tex; do \
	${INSTALL_DATA} $$i ${PREFIX}/share/emacs/site-lisp/calc ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/calc.info* ${PREFIX}/info
	@install-info --dir-file=${PREFIX}/info/dir \
	--info-file=${PREFIX}/info/calc.info

.include "../../mk/bsd.pkg.mk"
