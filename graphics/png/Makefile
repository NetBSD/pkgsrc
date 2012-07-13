# $NetBSD: Makefile,v 1.149.2.1 2012/07/13 08:51:00 tron Exp $

DISTNAME=	libpng-1.5.12
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/libpng.html
COMMENT=	Library for manipulating PNG images
LICENSE=	zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
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
