# $NetBSD: Makefile,v 1.24.2.1 2003/06/30 08:17:52 grant Exp $

.include "../ImageMagick/Makefile.common"

PKGNAME=		p5-PerlMagick-${DISTVERSION}

SVR4_PKGNAME=		p5pma

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

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--with-perl=${PERL5}

post-configure: perl5-configure

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
