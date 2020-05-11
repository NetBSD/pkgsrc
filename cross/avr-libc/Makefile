# $NetBSD: Makefile,v 1.53 2020/05/11 12:57:56 mef Exp $

DISTNAME=		avr-libc-2.0.0
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		http://savannah.nongnu.org/download/avr-libc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		https://savannah.nongnu.org/projects/avr-libc
COMMENT=		C and math library for Atmel AVR 8-bit microcontrollers
LICENSE=		modified-bsd

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=avr
CONFIGURE_ARGS+=	--disable-versioned-doc
CONFIGURE_ARGS+=	CC=${PREFIX}/bin/avr-gcc
CONFIGURE_ARGS+=	CPPFLAGS="-I${PREFIX}/include -I${PREFIX}/avr/include"

BUILD_DEPENDS+=		doxygen>=1.8.12:../../devel/doxygen
BUILD_DEPENDS+=		tex-hanging-[0-9]*:../../print/tex-hanging
BUILD_DEPENDS+=		tex-stackengine-[0-9]*:../../print/tex-stackengine
BUILD_DEPENDS+=		tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar
BUILD_DEPENDS+=		tex-etoc-[0-9]*:../../print/tex-etoc
BUILD_DEPENDS+=		tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg

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

.include "options.mk"
.include "../../cross/avr-binutils/buildlink3.mk"
.include "../../cross/avr-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Not to be overridden as --mandir=${PREFIX}, put the line here.
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/doc/avr-libc/man
