# $NetBSD: Makefile,v 1.59 2000/08/10 08:57:23 tron Exp $

DISTNAME=		ImageMagick-5.2.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

# Avoid compiler bug on "arm32"
.if (${MACHINE_ARCH} == arm32)
CFLAGS=			-O
.endif

# For things for which we do not specify an explicit dependency above, disable
# so that we don't cause implicit "hidden" dependencies.  Users may reenable
# any of these manually as desired (PerlMagick should probably be a separate
# pkg, however).
CONFIGURE_ARGS+=	--without-perl --without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../mk/bsd.pkg.mk"
