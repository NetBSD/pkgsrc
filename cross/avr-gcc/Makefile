# $NetBSD: Makefile,v 1.42 2018/08/22 09:43:10 wiz Exp $

DISTNAME=		gcc-4.8.3
PKGNAME=		${DISTNAME:C/^/avr-/}
PKGREVISION=		4
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/releases/${DISTNAME}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc-4.8 for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=		avr-binutils-[0-9]*:../../cross/avr-binutils

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++03
USE_TOOLS+=		bison gmake lex perl tar msgfmt autoconf pod2man
USE_PKGLOCALEDIR=	yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--enable-languages='c c++'
CONFIGURE_ARGS+=	--disable-nls --disable-lto
CONFIGURE_ARGS+=	--disable-libquadmath-support
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--disable-threads

MAKE_ENV+=		MACHINE_ARCH=avr
MAKE_ENV+=		SHELL=${CONFIG_SHELL}
MAKE_ENV+=		CFLAGS_FOR_BUILD=${CFLAGS_FOR_BUILD:Q}
MAKE_ENV+=		CXXFLAGS_FOR_BUILD=${CXXFLAGS_FOR_BUILD:Q}
MAKE_ENV+=		CPPFLAGS_FOR_BUILD=${CPPFLAGS_FOR_BUILD:Q}

SUBST_CLASSES+=		sed
SUBST_FILES.sed=	fixincludes/fixincl.x
SUBST_SED.sed=		-e 's|@SED@|${TOOLS_PATH.sed}|g'
SUBST_STAGE.sed=	pre-configure

pre-configure:
	${MKDIR} ${WRKDIR}/obj
	${LN} -s ${WRKDIR}/obj/gcc/include/unwind.h ${WRKSRC}/gcc/unwind.h

# To avoid the conflict with other cross and native compiler
post-install:
	(cd ${DESTDIR}${PREFIX}/lib; \
	 ${MV} libiberty.a gcc/avr/ )

CONFIGURE_DIRS=		${WRKDIR}/obj
CONFIGURE_SCRIPT=	${WRKSRC}/configure

INSTALLATION_DIRS+=	avr/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
# mpc is required since gcc-4.5.x
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

CFLAGS_FOR_BUILD:=	${CFLAGS}
CXXFLAGS_FOR_BUILD:=	${CXXFLAGS}
CPPFLAGS_FOR_BUILD:=	${CPPFLAGS}
CFLAGS:=		# empty
CPPFLAGS:=		# empty
CXXFLAGS:=		# empty
