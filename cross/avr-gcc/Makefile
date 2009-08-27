# $NetBSD: Makefile,v 1.21 2009/08/27 15:29:37 hasso Exp $

DISTNAME=		gcc-4.4.1
PKGNAME=		avr-gcc-4.4.1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/releases/${DISTNAME}/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME:S/-/-core-/}${EXTRACT_SUFX} \
			${DISTNAME:S/-/-g++-/}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc-4.4 for Atmel AVR 8-bit RISC microcontrollers

DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils
BUILD_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
USE_BZIP2=		yes
USE_TOOLS+=		bison gmake lex perl tar msgfmt
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--target=avr --disable-nls

MAKE_FLAGS+=		LANGUAGES="c c++"
MAKE_ENV+=		MACHINE_ARCH=avr
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
CFLAGS_FOR_BUILD:=	${CFLAGS}
MAVE_ENV+=		CFLAGS_FOR_BUILD=${CFLAGS_FOR_BUILD:Q}
CXXFLAGS_FOR_BUILD:=	${CXXFLAGS}
MAVE_ENV+=		CXXFLAGS_FOR_BUILD=${CXXFLAGS_FOR_BUILD:Q}
CFLAGS=			# empty
CXXFLAGS=		# empty

SUBST_CLASSES+=		sed
SUBST_FILES.sed=	fixincludes/fixincl.x
SUBST_SED.sed=		-e 's|@SED@|${TOOLS_PATH.sed}|g'
SUBST_STAGE.sed=	post-patch


do-configure:
	${MKDIR} ${WRKDIR}/obj
	cd ${WRKDIR}/obj; ${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ${WRKSRC}/configure ${CONFIGURE_ARGS}

do-build:
	(${_ULIMIT_CMD} cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1} )

do-install:
	cd ${WRKDIR}/obj && ${SETENV} ${MAKE_ENV} ${GMAKE} install

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
