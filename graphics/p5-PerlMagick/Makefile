# $NetBSD: Makefile,v 1.24 2003/01/03 23:04:39 wiz Exp $

DISTNAME=		ImageMagick-${IM_MAJOR_VER}-${IM_MINOR_VER}
PKGNAME=		p5-PerlMagick-${IM_MAJOR_VER}.${IM_MINOR_VER}
SVR4_PKGNAME=		p5pma
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Object-oriented Perl interface to ImageMagick

DISTINFO_FILE=		${.CURDIR}/../../graphics/ImageMagick/distinfo
FILESDIR=		${.CURDIR}/../../graphics/ImageMagick/files
PATCHDIR=		${.CURDIR}/../../graphics/ImageMagick/patches

IM_MAJOR_VER=		5.5.3
IM_MINOR_VER=		2

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK2=		YES

USE_PERL5=		run
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Magick/.packlist

GNU_CONFIGURE=		YES
USE_X11=		YES

WRKSRC=			${WRKDIR}/ImageMagick-${IM_MAJOR_VER}
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
