# $NetBSD: Makefile,v 1.78 2006/04/22 07:07:55 wiz Exp $

DISTNAME=	libpng-1.2.9
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.simplesystems.org/pub/libpng/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in
TEST_TARGET=	test
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	scripts/libpng-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to libpng-config.
SUBST_SED.rpathfix=	'/^L_opts=/s|-L\([	 ]*[^	 ]*\)"|${COMPILER_RPATH_FLAG}\1 -L\1"|g'
SUBST_STAGE.rpathfix=	pre-configure

# highly version dependent -- fix up libtool .la file contents, since
# just copying a .la file to a new filename is not enough
# PLIST breakage will show when it needs updating :)
post-install:
	cd ${PREFIX}/lib && \
		${SED} -e 's/png12/png/g' -e 's/0.9.0/3.9.0/' -e 's/so\.0/so\.3/g' \
			-e 's/libpng.0.dylib/libpng.3.dylib/g' \
			libpng.la > libpng.la.out && \
		${MV} libpng.la.out libpng.la

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
