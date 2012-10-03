# $NetBSD: Makefile,v 1.24 2012/10/03 00:10:29 asau Exp $

DISTNAME=		avr-libc-1.6.7
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers
LICENSE=		modified-bsd

BUILD_DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=		doxygen>=1.8.2:../../devel/doxygen
BUILD_DEPENDS+=		transfig-[0-9]*:../../print/transfig
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=		aclocal autoconf autoheader automake gmake
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST= no
CONFIGURE_ENV+=		AS=${PREFIX}/bin/avr-as
CONFIGURE_ENV+=		AR=${PREFIX}/bin/avr-ar
CONFIGURE_ENV+=		RANLIB=${PREFIX}/bin/avr-ranlib
CONFIGURE_ENV+=		CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q} --host=avr
CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

post-build:
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE}
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE} dox

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/avr-libc
	for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${DESTDIR}${PREFIX}/share/doc/avr-libc/examples/demo; \
	done

.include "../../mk/bsd.pkg.mk"

# XXX: very evil hack to override CC, doing it via CONFIGURE_ENV doesn't work.
ALL_ENV+= CC=${PREFIX}/bin/avr-gcc
