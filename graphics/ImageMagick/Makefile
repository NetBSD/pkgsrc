# $NetBSD: Makefile,v 1.68 2001/05/22 09:32:19 wiz Exp $

DISTNAME=		ImageMagick-5.2.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec
DEPENDS+=		png>=1.0.11:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

CONFLICTS=		geomview-*    # both have a program named 'animate'

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

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
			--without-ttf --without-wmf --without-xml

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../mk/bsd.pkg.mk"
