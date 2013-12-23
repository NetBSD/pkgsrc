# $NetBSD: Makefile,v 1.91 2013/12/23 11:57:04 wiz Exp $

DISTNAME=	freetype-2.4.12
PKGNAME=	${DISTNAME:S/-/2-/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/} \
		http://download.savannah.gnu.org/releases/freetype/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	Font rendering engine and library API
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		grep gmake
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		builds/unix
BUILD_DIRS=		.
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		ac_cv_path_GREP=${GREP:Q} ac_cv_path_EGREP=${EGREP:Q}

.if exists(/System/Library/Frameworks/Carbon.framework)
LDFLAGS+=	-framework Carbon
.endif

PKGCONFIG_OVERRIDE=	builds/unix/freetype2.in

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	subpixel

.include "../../mk/bsd.options.mk"

# subpixel (lcd) rendering, patent issues
.if !empty(PKG_OPTIONS:Msubpixel)
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

# source code breaks strict aliasing in gcc>=2.95
.if !empty(CC_VERSION:Mgcc-[3-9]*) || !empty(CC_VERSION:Mgcc-2.95*)
CFLAGS+=	-fno-strict-aliasing
.endif

# tell configure not to use unix-specific version of ftsystem.c on OpenBSD
.if ${OPSYS} == "OpenBSD"
CONFIGURE_ENV+=		ac_cv_func_mmap_fixed_mapped=no
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_BUILD=${NATIVE_CC:Q}
.endif

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk
.if ${OPSYS} == "IRIX"
	${MKDIR} ${WRKSRC}/.libs
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
