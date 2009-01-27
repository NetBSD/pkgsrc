# $NetBSD: Makefile,v 1.24 2009/01/27 21:55:04 sketch Exp $
#

.include "Makefile.common"

PKGREVISION=		1

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

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--disable-asm
.endif

# avoid installing docs
do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
	cd ${WRKSRC}/include && ${MAKE_ENV} ${MAKE} install
	cd ${WRKSRC}/lib && ${MAKE_ENV} ${MAKE} install

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
