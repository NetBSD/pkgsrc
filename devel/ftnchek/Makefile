# $NetBSD: Makefile,v 1.4 2001/03/15 23:48:22 jtb Exp $

DISTNAME=	ftnchek-3.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.dsm.fordham.edu/~ftnchek
COMMENT=	Static analyzer for Fortran programs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/libexec

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek/html
	@for i in FAQ INSTALL LICENSE README ftnchek.man dcl2inc.man \
	macro-doc.txt; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ftnchek; done
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/ftnchek/html

.include "../../mk/bsd.pkg.mk"
