# $NetBSD: Makefile,v 1.134 2023/11/09 22:27:01 wiz Exp $

DISTNAME=	freetype-2.13.2
PKGNAME=	${DISTNAME:S/-/2-/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}
MASTER_SITES+=	https://download.savannah.gnu.org/releases/freetype/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freetype.org/
COMMENT=	Font rendering engine and library API
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		grep gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		builds/unix
BUILD_DIRS=		.
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-harfbuzz=no
CONFIGURE_ENV+=		ac_cv_path_GREP=${GREP:Q} ac_cv_path_EGREP=${EGREP:Q}

# Remove this when all dependent packages have switched to pkg-config
CONFIGURE_ARGS+=	--enable-freetype-config

.if exists(/System/Library/Frameworks/Carbon.framework)
LDFLAGS+=	-framework Carbon
.endif

PKGCONFIG_OVERRIDE=	builds/unix/freetype2.in

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.include "options.mk"

# source code breaks strict aliasing in gcc>=2.95
.if ${CC_VERSION:Mgcc-[3-9]*} || ${CC_VERSION:Mgcc-2.95*}
CFLAGS+=	-fno-strict-aliasing
.endif

# tell configure not to use unix-specific version of ftsystem.c on OpenBSD
CONFIGURE_ENV.OpenBSD+=	ac_cv_func_mmap_fixed_mapped=no

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ENV+=		CC_BUILD=${NATIVE_CC:Q}
.endif

post-configure:
	cd ${WRKSRC} && ${LN} -f -s builds/unix/unix.mk config.mk
.if ${OPSYS} == "IRIX"
	${MKDIR} ${WRKSRC}/.libs
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
