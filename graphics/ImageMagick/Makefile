# $NetBSD: Makefile,v 1.46 1999/07/22 16:44:35 tron Exp $
#

DISTNAME=	ImageMagick-4.2.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mpeg2codec-1.2:../../graphics/mpeg2codec
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff

MIRROR_DISTFILE= no
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

# For things for which we do not specify an explicit dependency above, disable
# so that we don't cause implicit "hidden" dependencies.  Users may reenable
# any of these manually as desired (PerlMagick should probably be a separate
# pkg, however).

CONFIGURE_ARGS=	--without-perl \
		--without-dps --without-fpx --without-hdf --without-jbig \
		--without-ttf

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../mk/bsd.pkg.mk"
