# $NetBSD: Makefile,v 1.7 2001/12/19 01:09:25 dmcmahill Exp $
#

DISTNAME=	yacas-1.0.48
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/backups/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~apinkus/yacas.html
COMMENT=	Yet Another Computer Algebra System

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/yacas.el ${PREFIX}/share/emacs/site-lisp

test: build
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_PROGRAM} test 2>&1 | \
		tee ${WRKDIR}/tests.log

.include "../../mk/bsd.pkg.mk"
