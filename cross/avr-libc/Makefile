# $NetBSD: Makefile,v 1.1.1.1 2003/07/17 18:50:22 wennmach Exp $
# FreeBSD Id: ports/devel/avr-libc/Makefile,v 1.22 2003/05/20 06:02:40 joerg Exp

DISTNAME=		avr-libc-2003.05.11
CATEGORIES=		cross
MASTER_SITES=		http://people.freebsd.org/~joerg/ \
			http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		karlj@mdstud.chalmers.se
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for the Atmel AVR controller family

BUILD_DEPENDS+=		avr-binutils-*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-*:../../cross/avr-gcc
BUILD_DEPENDS+=		gmake-*:../../devel/gmake
BUILD_DEPENDS+=		doxygen-*:../../devel/doxygen
BUILD_DEPENDS+=		transfig-*:../../print/transfig
BUILD_DEPENDS+=		netpbm-*:../../graphics/netpbm

USE_BZIP2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ENV=		CC=${LOCALBASE}/bin/avr-gcc PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./doconf
CONFIGURE_ARGS=		--disable-versioned-doc --enable-html-doc --enable-doc

do-build:
	(cd ${WRKSRC}; ./domake MAKE=${GMAKE})

do-install:
	(cd ${WRKSRC}; ./domake MAKE=${GMAKE} install)
	${MKDIR} ${PREFIX}/share/doc/avr-libc
	${MKDIR} ${PREFIX}/share/doc/avr-libc/examples
	${MKDIR} ${PREFIX}/share/doc/avr-libc/examples/demo
	${MKDIR} ${PREFIX}/share/doc/avr-libc/examples/twitest
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${PREFIX}/share/doc/avr-libc
	@for f in avr-recv.c io.c prg printf.h progmem.c \
		send_byte.s signal.c;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/$$f \
			${PREFIX}/share/doc/avr-libc/examples; \
	done
	(cd ${WRKSRC}/doc/examples/demo; ${GMAKE})
	(cd ${WRKSRC}/doc/examples/demo; ${GMAKE} dox)
	@for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${PREFIX}/share/doc/avr-libc/examples/demo; \
	done
	@for f in Makefile twitest.c;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/twitest/$$f \
			${PREFIX}/share/doc/avr-libc/examples/twitest; \
	done

.include "../../mk/bsd.pkg.mk"
