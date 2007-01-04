# $NetBSD: Makefile,v 1.86.2.1 2007/01/04 15:09:26 salo Exp $

DISTNAME=	libpng-1.2.14
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
# temporary, distfile was changed after release
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.simplesystems.org/pub/libpng/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
DIST_SUBDIR=	libpng-1.2.14-20061130
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in
TEST_TARGET=	check
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"
# keep this in sync with the same code in buildlink3.mk
.if ${MACHINE_ARCH} != "i386"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	scripts/libpng-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to libpng-config.
SUBST_SED.rpathfix=	-e '/^L_opts=/s|-L\([	 ]*[^	 ]*\)"|${COMPILER_RPATH_FLAG}\1 -L\1"|g'
SUBST_STAGE.rpathfix=	pre-configure

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
