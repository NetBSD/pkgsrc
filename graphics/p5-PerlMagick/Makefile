# $NetBSD: Makefile,v 1.26 2003/04/15 11:11:50 mjl Exp $

IM_MAJOR_VER=		5.5.6
IM_MINOR_VER=		NONE
IM_MAJOR_LIB_VER=	${IM_MAJOR_VER}-Q16

.if (${IM_MINOR_VER} != NONE)
DISTNAME=		ImageMagick-${IM_MAJOR_VER}-${IM_MINOR_VER}
PKGNAME=		p5-PerlMagick-${IM_MAJOR_VER}.${IM_MINOR_VER}
.else
DISTNAME=		ImageMagick-${IM_MAJOR_VER}
PKGNAME=		p5-PerlMagick-${IM_MAJOR_VER}
.endif
SVR4_PKGNAME=		p5pma
WRKSRC=			${WRKDIR}/ImageMagick-${IM_MAJOR_VER}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/ \
			ftp://ftp.sunet.se/pub/multimedia/graphics/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Object-oriented Perl interface to ImageMagick

DISTINFO_FILE=		${.CURDIR}/../../graphics/ImageMagick/distinfo
FILESDIR=		${.CURDIR}/../../graphics/ImageMagick/files
PATCHDIR=		${.CURDIR}/../../graphics/ImageMagick/patches

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK2=		YES

USE_PERL5=		run
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Magick/.packlist

GNU_CONFIGURE=		YES
USE_X11=		YES

PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

post-configure: perl5-configure

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
