# $NetBSD: Makefile,v 1.6 2023/08/09 08:24:40 nia Exp $

DISTNAME=		gcc-8.3.0
PKGNAME=		cross-powerpc-none-elf-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		cross
NEWLIBVER=		3.1.0
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		port-powerpc@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal PowerPC ELF

EXTRACT_USING=		bsdtar

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=			gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

DEPENDS+=		cross-powerpc-none-elf-binutils-[0-9]*:../../cross/powerpc-none-elf-binutils

USE_LANGUAGES+=		c c++

POWERPCELF_PREFIX=	${PREFIX}/cross-powerpc-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CHECK_PORTABILITY_SKIP+= contrib/* # not needed for building

GNU_CONFIGURE_PREFIX=	${POWERPCELF_PREFIX}

CONFIGURE_ARGS+=	--target=powerpc-none-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
