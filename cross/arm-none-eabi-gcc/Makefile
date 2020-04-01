# $NetBSD: Makefile,v 1.27 2020/04/01 17:44:06 tnn Exp $

DISTNAME=		gcc-8.3.0
PKGNAME=		cross-arm-none-eabi-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		cross
NEWLIBVER=		3.1.0
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal ARM EABI

EXTRACT_USING=		bsdtar

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=			gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

DEPENDS+=		cross-arm-none-eabi-binutils-[0-9]*:../../cross/arm-none-eabi-binutils

USE_LANGUAGES+=		c c++

ARMELF_PREFIX=		${PREFIX}/cross-arm-none-eabi
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl
GNU_CONFIGURE=		yes
CHECK_PORTABILITY_SKIP+=contrib/*

GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

CONFIGURE_ARGS+=	--target=arm-none-eabi
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

INFO_FILES=		yes

PLIST_VARS+=		libcpp

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin"
PLIST.libcpp=	yes
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
