# $NetBSD: Makefile,v 1.31 2012/10/08 09:21:07 asau Exp $
#

.include "Makefile.common"

PKGREVISION=		2
PKGCONFIG_OVERRIDE=	theora.pc.in theoradec.pc.in theoraenc.pc.in
USE_LIBTOOL=		YES
TEST_TARGET=		check

# disable doxygen, see libtheora-docs package
# also, disable transfig, and *tex.

CONFIGURE_ENV+=		HAVE_DOXYGEN=no
CONFIGURE_ENV+=		HAVE_TRANSFIG=no
CONFIGURE_ENV+=		HAVE_BIBTEX=no
CONFIGURE_ENV+=		HAVE_PDFLATEX=no

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro) || \
    !empty(MACHINE_PLATFORM:MDarwin-9.*-i386) || \
    !empty(MACHINE_PLATFORM:MDarwin-??.*-*)
CONFIGURE_ARGS+=	--disable-asm
.endif

# avoid installing docs
INSTALL_DIRS=	include lib

post-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} install-pkgconfigDATA

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
