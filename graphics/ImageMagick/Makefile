# $NetBSD: Makefile,v 1.75 2001/08/29 22:41:14 jlam Exp $

DISTNAME=		ImageMagick-5.2.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

CONFLICTS=		geomview-*    # both have a program named 'animate'

DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	Magick++/bin/Magick++-config
REPLACE_BUILDLINK+=	magick/Magick-config

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

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

.include "../../archivers/bzip2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
