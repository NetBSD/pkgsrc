# $NetBSD: Makefile,v 1.22.2.1 2009/01/22 20:18:30 tron Exp $
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

# avoid installing docs
do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
	cd ${WRKSRC}/include && ${MAKE_ENV} ${MAKE} install
	cd ${WRKSRC}/lib && ${MAKE_ENV} ${MAKE} install

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
