# $NetBSD: Makefile,v 1.19 2002/09/26 12:46:40 seb Exp $

DISTNAME=		ImageMagick-5.4.8-2
PKGNAME=		p5-PerlMagick-5.4.8.2
SVR4_PKGNAME=		p5pma
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.nluug.nl/pub/ImageMagick/ \
			ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Object-oriented Perl interface to ImageMagick

DEPENDS+=		${DISTNAME:S/-2/.2/}:../../graphics/ImageMagick

DISTINFO_FILE=		${.CURDIR}/../../graphics/ImageMagick/distinfo
FILESDIR=		${.CURDIR}/../../graphics/ImageMagick/files
PATCHDIR=		${.CURDIR}/../../graphics/ImageMagick/patches

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Magick/.packlist

GNU_CONFIGURE=		YES
USE_X11=		YES

WRKSRC=			${WRKDIR}/${DISTNAME:S/-2//}
PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

# These need to coordinate with the ImageMagick package.
# Just leave out "--without-perl".

CONFIGURE_ARGS+=	--with-perl=${PERL5} \
			--without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-xml

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
BUILD_DEPENDS+=		bash>=2.0:../../shells/bash2

CONFIGURE_SCRIPT=	${LOCALBASE}/bin/bash ./configure
.endif

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
