# $NetBSD: Makefile,v 1.5 2017/05/16 17:52:18 ryoon Exp $

DISTNAME=		gcc-7.1.0
PKGNAME=		cross-arm-none-eabi-${DISTNAME}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
NEWLIBVER=              2.5.0
SITES.newlib-${NEWLIBVER}.tar.gz=ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			newlib-${NEWLIBVER}.tar.gz

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal ARM EABI
EXTRACT_SUFX=		.tar.gz

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=yes

DEPENDS+=	cross-arm-none-eabi-binutils-[0-9]*:../../cross/arm-none-eabi-binutils

USE_LANGUAGES+=		c c++

ARMELF_PREFIX=		${PREFIX}/cross-arm-none-eabi
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash perl

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

HOSTDIR=		build-${MACHINE_ARCH}--${LOWER_OPSYS}

CONFIGURE_ARGS+=	--target=arm-none-eabi
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# geattrtab on neon.md results in a very deeply nested expression
# with > 255 brackets. This was reported against GCC 4.9.1 at least
# already, but it seems noone cares enough in GCC to fix the generator.
CFLAGS+=	-fbracket-depth=1024
.endif

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
