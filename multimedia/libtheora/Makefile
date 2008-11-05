# $NetBSD: Makefile,v 1.20 2008/11/05 14:23:44 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		1

PKGCONFIG_OVERRIDE=	theora.pc.in theoradec.pc.in theoraenc.pc.in
USE_LIBTOOL=		YES
TEST_TARGET=		check

# disable doxygen, see libtheora-docs package
CONFIGURE_ENV+=		HAVE_DOXYGEN=no

# avoid installing docs
do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
	cd ${WRKSRC}/include && ${MAKE_ENV} ${MAKE} install
	cd ${WRKSRC}/lib && ${MAKE_ENV} ${MAKE} install

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
