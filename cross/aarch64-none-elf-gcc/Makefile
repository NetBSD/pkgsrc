# $NetBSD: Makefile,v 1.4 2018/08/22 09:43:10 wiz Exp $

DISTNAME=		gcc-7.2.0
PKGNAME=		cross-aarch64-none-elf-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
NEWLIBVER=              2.5.0
SITES.newlib-${NEWLIBVER}.tar.gz=ftp://sources.redhat.com/pub/newlib/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			newlib-${NEWLIBVER}.tar.gz

MAINTAINER=		port-arm@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal AArch64 ELF
EXTRACT_SUFX=		.tar.gz

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=yes

DEPENDS+=	cross-aarch64-none-elf-binutils-[0-9]*:../../cross/aarch64-none-elf-binutils

USE_LANGUAGES+=		c c++

AARCH64ELF_PREFIX=	${PREFIX}/cross-aarch64-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash perl

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${AARCH64ELF_PREFIX}

HOSTDIR=		build-${MACHINE_ARCH}--${LOWER_OPSYS}

CONFIGURE_ARGS+=	--target=aarch64-none-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

.include "../../mk/compiler.mk"

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
