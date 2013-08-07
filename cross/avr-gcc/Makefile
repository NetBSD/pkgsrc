# $NetBSD: Makefile,v 1.30 2013/08/07 03:11:35 mef Exp $

DISTNAME=		gcc-4.5.3
PKGNAME=		avr-gcc-4.5.3
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/releases/${DISTNAME}/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME:S/-/-core-/}${EXTRACT_SUFX} \
			${DISTNAME:S/-/-g++-/}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc-4.5 for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v3

DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes

USE_TOOLS+=		bison gmake lex perl tar msgfmt autoconf pod2man
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-multilib

MAKE_ENV+=		MACHINE_ARCH=avr
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
CFLAGS_FOR_BUILD:=	${CFLAGS}
MAKE_ENV+=		CFLAGS_FOR_BUILD=${CFLAGS_FOR_BUILD:Q}
CXXFLAGS_FOR_BUILD:=	${CXXFLAGS}
MAKE_ENV+=		CXXFLAGS_FOR_BUILD=${CXXFLAGS_FOR_BUILD:Q}
CFLAGS=			# empty
CXXFLAGS=		# empty

SUBST_CLASSES+=		sed
SUBST_FILES.sed=	fixincludes/fixincl.x
SUBST_SED.sed=		-e 's|@SED@|${TOOLS_PATH.sed}|g'
SUBST_STAGE.sed=	post-patch

pre-configure:
	${MKDIR} ${WRKDIR}/obj

CONFIGURE_DIRS=		${WRKDIR}/obj
CONFIGURE_SCRIPT=	${WRKSRC}/configure

INSTALLATION_DIRS+=	avr/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
# mpc is required since gcc-4.5.x
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
