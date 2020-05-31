# $NetBSD: Makefile,v 1.31 2020/05/31 14:11:42 mef Exp $
#
DISTNAME=		simulavr-1.0.0
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		http://download.savannah.gnu.org/releases/simulavr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.nongnu.org/simulavr/
COMMENT=		Simulator for Atmel AVR microcontrollers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		avr-libc-[0-9]*:../../cross/avr-libc

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--enable-python=python${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--with-bfd=${PREFIX}/avr
CONFIGURE_ARGS+=	--with-libiberty=${PREFIX}/lib/gcc/avr
CONFIGURE_ENV+=		TEX=no

# Following line does not work yet (examples/python directory)
#CONFIGURE_ENV+=	az_python_use=true
#MAKE_ENV+=		az_python_use=true

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		makeinfo gmake
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

# Interim fix
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix include path finding Python.h
SUBST_FILES.prefix=	src/Makefile.in
SUBST_VARS.prefix=	PREFIX
SUBST_VARS.prefix+=	PY_VER_SUFFIX

# Following SUBST_CLASSES are from diff against git version (as of 2013-08-08)
# See also
#  http://savannah.nongnu.org/bugs/?35737
SUBST_CLASSES+=		compare2
SUBST_STAGE.compare2=	pre-configure
SUBST_MESSAGE.compare2=	Convert poisoned SIG_OUTPUT_COMPARE2 to TIMER2_COMP_vect
SUBST_FILES.compare2=	examples/atmega128_timer/main.c
SUBST_FILES.compare2+=	examples/python/example.c
SUBST_FILES.compare2+=	examples/python/example_io.c
SUBST_FILES.compare2+=	examples/python/ex_pinout.c
SUBST_FILES.compare2+=	regress/timertest/timer_8bit_ctc.c
SUBST_SED.compare2=	-e 's/SIG_OUTPUT_COMPARE2/TIMER2_COMP_vect/g'

# StdDefs.h:66:33: error: attempt to use poisoned "SIG_UART0_RECV"
# StdDefs.h:67:39: error: attempt to use poisoned "SIG_UART0_DATA"
# kb.c:39:8: error: attempt to use poisoned "SIG_INTERRUPT0"

SUBST_CLASSES+=		uart0
SUBST_STAGE.uart0=	pre-configure
SUBST_MESSAGE.uart0=	Convert poisoned SIG_UART0_RECV to USART0_RX_vect
SUBST_FILES.uart0=	examples/atmel_key/StdDefs.h
SUBST_SED.uart0=	-e 's/SIG_UART0_RECV/USART0_RX_vect/g'
SUBST_SED.uart0+=	-e 's/SIG_UART0_DATA/USART0_UDRE_vect/g'

SUBST_CLASSES+=		intrpt0
SUBST_STAGE.intrpt0=	pre-configure
SUBST_MESSAGE.intrpt0=	Convert poisoned SIG_INTERRUPT0 to INT0_vect
SUBST_FILES.intrpt0=	examples/atmel_key/kb.c
SUBST_FILES.intrpt0+=	examples/python/multicore.c
SUBST_FILES.intrpt0+=	regress/extinttest/ext_int0.c
SUBST_SED.intrpt0=	-e 's/SIG_INTERRUPT0/INT0_vect/g'

# Following case, see patches
# regress/timertest/timer_16bit.c:ISR(SIG_OUTPUT_COMPARE3B) {

SUBST_CLASSES+=		makeinfo
SUBST_STAGE.makeinfo=	post-configure
SUBST_MESSAGE.makeinfo=	set MAKEINFO path (to avoid work-directory references included)
SUBST_FILES.makeinfo=	examples/anacomp/Makefile.in
SUBST_FILES.makeinfo+=	examples/python/Makefile.in
SUBST_SED.makeinfo=	-e 's,@MAKEINFO@,${PREFIX}/bin/makeinfo,g'

# gcc 2.95 gives warnings that it cannot inline all functions.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../cross/avr-binutils/buildlink3.mk"
.include "../../cross/avr-gcc/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
