# $NetBSD: Makefile,v 1.13 2023/08/09 08:24:40 nia Exp $

DISTNAME=		gcc-12.2.0
PKGNAME=		cross-pdp11-aout-${DISTNAME}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for PDP-11 aout

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo= yes

DEPENDS+=	cross-pdp11-aout-binutils-[0-9]*:../../cross/pdp11-aout-binutils

USE_LANGUAGES+=		c c++

PDP11AOUT_PREFIX=	${PREFIX}/cross-pdp11-aout
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash perl

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CHECK_PORTABILITY_SKIP+= contrib/* # not needed for building

GNU_CONFIGURE_PREFIX=	${PDP11AOUT_PREFIX}

HOSTDIR=		build-${MACHINE_ARCH}--${LOWER_OPSYS}

CONFIGURE_ARGS+=	--target=pdp11-aout
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
#CONFIGURE_ARGS+=	--disable-threads
#CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libstdc++-v3
CONFIGURE_ARGS+=	--disable-gcov

INFO_FILES=		yes

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# geattrtab on neon.md results in a very deeply nested expression
# with > 255 brackets. This was reported against GCC 4.9.1 at least
# already, but it seems noone cares enough in GCC to fix the generator.
CFLAGS+=	-fbracket-depth=1024
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
