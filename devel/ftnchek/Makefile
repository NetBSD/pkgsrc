# $NetBSD: Makefile,v 1.6 2001/04/25 23:24:45 jtb Exp $

DISTNAME=	ftnchek-3.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dsm.fordham.edu/~ftnchek
COMMENT=	Static analyzer for Fortran programs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/libexec

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ftnchek/html
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ INSTALL LICENSE README 	\
		ftnchek.man dcl2inc.man macro-doc.txt 			\
		${PREFIX}/share/doc/ftnchek
	${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/ftnchek/html

.include "../../mk/bsd.pkg.mk"
