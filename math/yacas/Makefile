# $NetBSD: Makefile,v 1.9 2003/07/12 13:23:05 dillo Exp $
#

DISTNAME=	yacas-1.0.48
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/backups/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~apinkus/yacas.html
COMMENT=	Yet Another Computer Algebra System

GNU_CONFIGURE=	YES

TEST_TARGET=	test

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/yacas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
