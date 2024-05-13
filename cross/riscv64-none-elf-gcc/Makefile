# $NetBSD: Makefile,v 1.3 2024/05/13 23:08:56 gutteridge Exp $

DISTNAME=		gcc-13.2.0
PKGNAME=		cross-riscv64-none-elf-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		cross
NEWLIBVER=		4.4.0.20231231
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		port-riscv@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal RISC-V 64-bit little-endian ELF
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

EXTRACT_USING=		bsdtar

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=			gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

DEPENDS+=		cross-riscv64-none-elf-binutils-[0-9]*:../../cross/riscv64-none-elf-binutils

USE_LANGUAGES+=		c c++

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh

RISCV64ELF_PREFIX=	${PREFIX}/cross-riscv64-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
GNU_CONFIGURE_PREFIX=	${RISCV64ELF_PREFIX}

CONFIGURE_ARGS+=	--target=riscv64-none-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-gcov

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
