# $NetBSD: Makefile,v 1.167 2014/02/06 18:24:11 wiz Exp $

DISTNAME=	libpng-1.6.9
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/libpng16/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/libpng.html
COMMENT=	Library for manipulating PNG images
LICENSE=	zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
# do not create libpng.la
CONFIGURE_ARGS+=	--disable-unversioned-links
# but do install png.h outside include/libpng$VERSION for now
# until pkgsrc is fixed to use libpng-config or the pc file everywhere
INSTALL_TARGET=	install install-header-links

PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in libpng.pc.in
TEST_TARGET=	check
USE_LIBTOOL=	yes

CPPFLAGS+=	-DPNG_USER_CHUNK_CACHE_MAX=128 -DPNG_USER_CHUNK_MALLOC_MAX=8000000

.include "../../mk/bsd.prefs.mk"
# keep this in sync with the same code in buildlink3.mk
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	libpng-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to libpng-config
SUBST_SED.rpathfix=	-e 's/-L$${libdir}/${COMPILER_RPATH_FLAG}$${libdir} -L$${libdir}/g'
SUBST_STAGE.rpathfix=	pre-configure

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
