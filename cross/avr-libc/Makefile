# $NetBSD: Makefile,v 1.31 2014/02/14 13:28:49 joerg Exp $

DISTNAME=		avr-libc-1.8.0
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers
LICENSE=		modified-bsd

BUILD_DEPENDS+=		doxygen>=1.8.6:../../devel/doxygen
BUILD_DEPENDS+=		transfig-[0-9]*:../../print/transfig
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST= no

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--host=avr
CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc

#   In doc/examples/demo directory, we have sample Makefile both for
#   generating *.hex file at pkg installation time, and for installing
#   Makefile itself.  That Makefile should be for general purpose, meaning
#     OBJCOPY = avr-objcopy
#   line should be intact. While pkg installation time it should refer
#   wrapper ${LOCALBASE}/cross/bin files. See patch-doc_Makefile.in adding
#   related one line.

SUBST_CLASSES+=		demo
SUBST_STAGE.demo=	pre-configure
SUBST_MESSAGE.demo=	Add cross/bin on PATH for OBJCOPY (avr-objcopy) etc
SUBST_FILES.demo=	doc/Makefile.in
SUBST_SED.demo=		-e 's|@@@PATH@@@|${PREFIX}/bin:${PATH:Q}|g'

post-extract:
	${MKDIR} ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-setup.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-wiring.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/largedemo/largedemo-wiring2.jpg ${WRKSRC}/doc/api/latex_src
	${LN} -s ../../examples/stdiodemo/stdiodemo-setup.jpg ${WRKSRC}/doc/api/latex_src

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/avr-libc
	## delete following or similar files, which includes PATH at build time.
	##_usr_pkgsrc_cross_avr-libc_work_avr-libc-1.8.0_libc_string_.3
	(cd ${DESTDIR}${PREFIX}/share/doc/avr-libc/man/man3; ${RM} -f *${PKGVERSION_NOREV}*)
	set -e;	\
	for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${DESTDIR}${PREFIX}/share/doc/avr-libc/examples/demo; \
	done

.include "../../cross/avr-binutils/buildlink3.mk"
.include "../../cross/avr-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX: very evil hack to override CC, doing it via CONFIGURE_ENV doesn't work.
#MAKE_ENV+=		CC=${PREFIX}/bin/avr-gcc
#MAKE_ENV is overwritten by CC=gcc in ALL_ENV
ALL_ENV+= CC=${PREFIX}/bin/avr-gcc
# Not to be overridden as --mandir=${PREFIX}, put the line here.
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/doc/avr-libc/man
