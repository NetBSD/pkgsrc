# $NetBSD: Makefile,v 1.8 2006/01/24 07:31:59 wiz Exp $

DISTNAME=		avr-libc-1.2.5
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		http://people.freebsd.org/~joerg/ \
			http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers

BUILD_DEPENDS+=		avr-binutils-*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen-*:../../devel/doxygen
BUILD_DEPENDS+=		transfig-*:../../print/transfig
BUILD_DEPENDS+=		netpbm-*:../../graphics/netpbm

USE_BZIP2=		yes
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		CC=${LOCALBASE}/bin/avr-gcc
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc
# avr-libc's method to build the man pages seems to be broken
CONFIGURE_ARGS+=	--disable-man-doc
CONFIGURE_SCRIPT=	${SRCDIR}/doconf
SRCDIR=			${WRKDIR}/${DISTNAME}

do-build:
	(cd ${WRKSRC}; ./domake MAKE=${GMAKE})

do-install:
	(cd ${WRKSRC}; ./domake MAKE=${GMAKE} install)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples/demo
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples/twitest
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
