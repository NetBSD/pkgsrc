# $NetBSD: Makefile,v 1.14 2009/05/28 20:59:54 zafer Exp $

DISTNAME=		avr-libc-1.2.5
PKGREVISION=		4
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen>=1.4.7:../../devel/doxygen
BUILD_DEPENDS+=		transfig-[0-9]*:../../print/transfig
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=		gmake
USE_TOOLS+=		perl
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		AS=${PREFIX}/bin/avr-as
CONFIGURE_ENV+=		AR=${PREFIX}/bin/avr-ar
CONFIGURE_ENV+=		RANLIB=${PREFIX}/bin/avr-ranlib
CONFIGURE_ENV+=		CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc
# avr-libc's method to build the man pages seems to be broken
CONFIGURE_ARGS+=	--disable-man-doc
CONFIGURE_SCRIPT=	${SRCDIR}/doconf
SRCDIR=			${WRKDIR}/${DISTNAME}

post-extract:
	${INSTALL} -m 755 ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/config.guess

do-build:
	cd ${WRKSRC} && ./domake MAKE=${GMAKE:Q}

do-install:
	cd ${WRKSRC} && ./domake MAKE=${GMAKE:Q} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples/demo
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avr-libc/examples/twitest
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${PREFIX}/share/doc/avr-libc
	for f in avr-recv.c io.c prg printf.h progmem.c \
		send_byte.s signal.c;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/$$f \
			${PREFIX}/share/doc/avr-libc/examples; \
	done
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE}
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE} dox
	for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${PREFIX}/share/doc/avr-libc/examples/demo; \
	done
	for f in Makefile twitest.c;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/twitest/$$f \
			${PREFIX}/share/doc/avr-libc/examples/twitest; \
	done

.include "../../mk/bsd.pkg.mk"
