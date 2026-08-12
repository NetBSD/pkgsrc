# $NetBSD: Makefile,v 1.1 2026/08/12 16:25:19 ryoon Exp $

DISTNAME=		gcc-ia16
PKGNAME=		ia16-elf-gcc-bootstrap-6.3.0pre20260612
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITLAB:=tkchia/}
GITLAB_PROJECT=		gcc-ia16
GITLAB_TAG=		9a5539544a9095ad35c4f57a23f2b79461032cb2

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://gitlab.com/tkchia/gcc-ia16
COMMENT=		Bootstrap GCC for IA16 ELF cross environment
LICENSE=		gnu-gpl-v3

ISL16=			isl-0.16.1
SITES.${ISL16}.tar.bz2=	${MASTER_SITE_GNU:=gcc/infrastructure/}
EXTRA_DISTFILES+=	${ISL16}.tar.bz2

DISTFILES+=		${DEFAULT_DISTFILES} ${EXTRA_DISTFILES}

DEPENDS+=		ia16-elf-binutils-bootstrap-[0-9]*:../../cross/ia16-elf-binutils-bootstrap

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

WRKSRC=			${WRKDIR}/${DISTNAME}-${GITLAB_TAG}

USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross/ia16-elf-bootstrap
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo perl:build
INFO_FILES=		yes

USE_GNU_CONFIGURE_TARGET=	yes
TARGET_MACHINE_GNU_PLATFORM=	ia16-elf

OBJDIR=			../build
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_STRICT=	no # has sub-configures
CONFIGURE_DIRS=		${OBJDIR}

# A different sysroot causes "exec: Unknown option -o" error from xgcc.
CONFIGURE_ARGS+=	--with-sysroot=${GNU_CONFIGURE_PREFIX}
CONFIGURE_ARGS+=	--without-headers
CONFIGURE_ARGS+=	--with-newlib
#CONFIGURE_ARGS+=	--with-ld=${PREFIX}/cross/ia16-elf/ia16-elf/bin/ld
#CONFIGURE_ARGS+=	--with-as=${PREFIX}/cross/ia16-elf/ia16-elf/bin/as
CONFIGURE_ARGS+=	--with-build-time-tools=${PREFIX}/cross/ia16-elf/bin
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libstdcxx
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}

#CONFIGURE_ENV+=		inhibit_libc=true
#CONFIGURE_ENV+=		AR_FOR_TARGET=${PREFIX}/cross/ia16-elf-bootstrap/bin/ia16-elf-ar

post-extract:
	${LN} -sf ${WRKDIR}/${ISL16} ${WRKSRC}/isl

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

post-configure:
	# Avoid "no usable dependency style found" errors in gcc/ and libcpp/
	${LN} -sf ${_OVERRIDE_PATH.depcomp} ${WRKSRC}/depcomp

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
