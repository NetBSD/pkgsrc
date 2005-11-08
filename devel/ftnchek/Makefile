# $NetBSD: Makefile,v 1.14 2005/11/08 03:36:58 tv Exp $

DISTNAME=	ftnchek-3.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.dsm.fordham.edu/~ftnchek/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dsm.fordham.edu/~ftnchek/
COMMENT=	Static analyzer for Fortran programs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/libexec
CONFIGURE_ARGS+=--disable-submodel

USE_TOOLS+=	soelim

.if (${MACHINE_ARCH} == "arm")
CFLAGS+=	-O1
.endif

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
