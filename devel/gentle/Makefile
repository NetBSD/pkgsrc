# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=		gentle-97
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.cuhk.hk/pub/Linux/devel/compiler-tools/

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://gentle.compilertools.net/distribution.html
COMMENT=		Gentle Compiler Construction System

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin lib

do-build:
	(cd ${WRKSRC}/gentle ; LIBTOOL=${LOCALBASE}/bin/libtool ./build)
	(cd ${WRKSRC}/lib ; LIBTOOL=${LOCALBASE}/bin/libtool ./build)
	(cd ${WRKSRC}/reflex ; LIBTOOL=${LOCALBASE}/bin/libtool ./build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gentle/gentle ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/gentle/grts.o ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libgentle.la ${PREFIX}/lib
	${LIBTOOL} --mode=finish ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/reflex/reflex ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/gentle/html
	(for i in ${WRKSRC}/html/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/html/gentle/html ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/BOOK.html ${PREFIX}/share/doc/html/gentle
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gentle
	${INSTALL_DATA} ${WRKSRC}/BOOK.ps ${PREFIX}/share/doc/gentle
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gentle
	(for i in calc flat micro nested polish virtual ; do \
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gentle/$$i ; \
	for j in ${WRKSRC}/examples/$$i/* ; do \
	${INSTALL_DATA} $$j ${PREFIX}/share/examples/gentle/$$i ; \
	done ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/examples/README ${PREFIX}/share/examples/gentle

.include "../../mk/bsd.pkg.mk"

