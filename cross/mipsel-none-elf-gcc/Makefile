# $NetBSD: Makefile,v 1.1 2020/06/20 14:33:35 thorpej Exp $

DISTNAME=		gcc-8.3.0
PKGNAME=		cross-mipsel-none-elf-${DISTNAME}
CATEGORIES=		cross
NEWLIBVER=		3.1.0
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		port-mips@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal MIPS 32-bit little-endian ELF

EXTRACT_USING=		bsdtar

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=			gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

DEPENDS+=		cross-mipsel-none-elf-binutils-[0-9]*:../../cross/mipsel-none-elf-binutils

USE_LANGUAGES+=		c c++

MIPSELELF_PREFIX=	${PREFIX}/cross-mipsel-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CHECK_PORTABILITY_SKIP+= contrib/* # not needed for building

GNU_CONFIGURE_PREFIX=	${MIPSELELF_PREFIX}

CONFIGURE_ARGS+=	--target=mipsel-none-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
