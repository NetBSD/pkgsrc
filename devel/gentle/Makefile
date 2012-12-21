# $NetBSD: Makefile,v 1.10 2012/12/21 01:16:50 dholland Exp $
#

DISTNAME=		gentle-97
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://gentle.compilertools.net/

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://gentle.compilertools.net/
COMMENT=		Gentle Compiler Construction System

NOT_FOR_PLATFORM=	${LP64PLATFORMS}

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin lib

do-build:
	(cd ${WRKSRC}/gentle ; LIBTOOL=${LIBTOOL} CC=${CC} ./build)
	(cd ${WRKSRC}/lib ; LIBTOOL=${LIBTOOL} CC=${CC} ./build)
	(cd ${WRKSRC}/reflex ; LIBTOOL=${LIBTOOL} CC=${CC} ./build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gentle/gentle ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/gentle/grts.o ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libgentle.la \
		${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=finish ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/reflex/reflex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/gentle/html
	(for i in ${WRKSRC}/html/* ; do \
		${INSTALL_DATA} $$i \
			${DESTDIR}${PREFIX}/share/doc/html/gentle/html ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/BOOK.html \
		${DESTDIR}${PREFIX}/share/doc/html/gentle
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gentle
	${INSTALL_DATA} ${WRKSRC}/BOOK.ps ${DESTDIR}${PREFIX}/share/doc/gentle
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gentle
	(for i in calc flat micro nested polish virtual ; do \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gentle/$$i ; \
	for j in ${WRKSRC}/examples/$$i/* ; do \
	${INSTALL_DATA} $$j ${DESTDIR}${PREFIX}/share/examples/gentle/$$i ; \
	done ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/examples/README \
		${DESTDIR}${PREFIX}/share/examples/gentle

.include "../../mk/bsd.pkg.mk"
