# $NetBSD: Makefile,v 1.206 2024/02/24 09:39:59 wiz Exp $

DISTNAME=	libpng-1.6.43
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=libpng/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pnggroup/libpng
COMMENT=	Library for manipulating PNG images
LICENSE=	zlib

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# do not create libpng.la
CONFIGURE_ARGS+=	--disable-unversioned-links
# but do install png.h outside include/libpng$VERSION for now
# until pkgsrc is fixed to use libpng-config or the pc file everywhere
INSTALL_TARGET=		install install-header-links

PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in libpng.pc.in
TEST_TARGET=		check

CPPFLAGS+=	-DPNG_USER_CHUNK_CACHE_MAX=128 -DPNG_USER_CHUNK_MALLOC_MAX=8000000

.include "../../mk/bsd.prefs.mk"
# keep this in sync with the same code in buildlink3.mk
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	libpng-config.in
SUBST_VARS.rpathfix=	COMPILER_RPATH_FLAG
SUBST_STAGE.rpathfix=	post-build

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
