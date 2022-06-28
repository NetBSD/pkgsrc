# $NetBSD: Makefile,v 1.20 2022/06/28 11:31:13 wiz Exp $

DISTNAME=		gcc-8.2.0
PKGNAME=		cross-aarch64-none-elf-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
NEWLIBVER=		3.0.0
SITES.newlib-${NEWLIBVER}.tar.gz= https://www.sourceware.org/pub/newlib/
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
EXTRACT_USING=		bsdtar

MAINTAINER=		port-arm@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal AArch64 ELF
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3
EXTRACT_SUFX=		.tar.xz

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo= yes

DEPENDS+=	cross-aarch64-none-elf-binutils>=2.31.1nb1:../../cross/aarch64-none-elf-binutils

USE_LANGUAGES+=		c c++

AARCH64ELF_PREFIX=	${PREFIX}/cross-aarch64-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake makeinfo perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CHECK_PORTABILITY_SKIP+=contrib/*
MKPIE_SUPPORTED=	no # relocation errors on netbsd-9 aarch64

GNU_CONFIGURE_PREFIX=	${AARCH64ELF_PREFIX}

CONFIGURE_ARGS+=	--target=aarch64-none-elf
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
