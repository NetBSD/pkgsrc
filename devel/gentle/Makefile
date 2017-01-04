# $NetBSD: Makefile,v 1.14 2017/01/04 12:53:49 jperkin Exp $
#

DISTNAME=		gentle-97
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://gentle.compilertools.net/

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://gentle.compilertools.net/
COMMENT=		Gentle Compiler Construction System

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin lib share/doc/gentle/html share/examples/gentle

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

do-build:
	(cd ${WRKSRC}/gentle && LIBTOOL=${LIBTOOL:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} ./build)
	(cd ${WRKSRC}/lib && LIBTOOL=${LIBTOOL:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} ./build)
	(cd ${WRKSRC}/reflex && LIBTOOL=${LIBTOOL:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} ./build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gentle/gentle ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/gentle/grts.o ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libgentle.la \
		${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=finish ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/reflex/reflex ${DESTDIR}${PREFIX}/bin
	set -e; for i in ${WRKSRC}/html/* ; do \
		${INSTALL_DATA} "$$i" \
			${DESTDIR}${PREFIX}/share/doc/gentle/html ; \
	done
	${INSTALL_DATA} ${WRKSRC}/BOOK.html \
		${DESTDIR}${PREFIX}/share/doc/gentle
	${INSTALL_DATA} ${WRKSRC}/BOOK.ps ${DESTDIR}${PREFIX}/share/doc/gentle
.for i in calc flat micro nested polish virtual
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gentle/${i}
	set -e; for j in ${WRKSRC}/examples/${i}/* ; do \
		${INSTALL_DATA} "$$j" \
			${DESTDIR}${PREFIX}/share/examples/gentle/${i} ; \
	done
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/README \
		${DESTDIR}${PREFIX}/share/examples/gentle

.include "../../mk/bsd.pkg.mk"
