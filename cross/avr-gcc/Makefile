# $NetBSD: Makefile,v 1.49 2022/04/15 17:16:08 tnn Exp $

DISTNAME=		gcc-10.3.0
PKGREVISION=		1
PKGNAME=		${DISTNAME:C/^/avr-/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/${DISTNAME}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GCC for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

DEPENDS+=		avr-binutils>=2.37:../../cross/avr-binutils

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake gsed:run
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
CHECK_PORTABILITY_SKIP+=contrib/* # not needed for building


# Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}

CONFIGURE_ARGS+=	--enable-languages='c c++'
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-libcc1
CONFIGURE_ARGS+=	--disable-libquadmath-support
CONFIGURE_ARGS+=	--disable-lto
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--with-system-zlib

# XXX: Workaround for configure error:
#    checking dependency style of c++... none
#    configure: error: no usable dependency style found
MAKE_ENV+=		am_cv_CXX_dependencies_compiler_type=gcc3

# From lang/gcc10
MAKE_ENV.NetBSD+=	ac_cv_func_clock_gettime=yes
MAKE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
MAKE_ENV.NetBSD+=	ac_cv_func_freelocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_newlocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_uselocale=no
MAKE_ENV.SunOS+=	ac_cv_func_mkostemp=no

INSTALLATION_DIRS+=	avr/bin

.include "options.mk"

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

# Remove some manual pages from generic locations
# File paths from this package should not overlap with other GCC packages
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
