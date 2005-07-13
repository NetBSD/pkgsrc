# $NetBSD: Makefile,v 1.41 2005/07/13 18:01:31 jlam Exp $

.include "../../graphics/ImageMagick/Makefile.common"

PKGNAME=	p5-PerlMagick-${DISTVERSION}

SVR4_PKGNAME=	p5pma

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.simplesystems.org/ImageMagick/
COMMENT=	Object-oriented Perl interface to ImageMagick

DISTINFO_FILE=	${.CURDIR}/../../graphics/ImageMagick/distinfo
FILESDIR=	${.CURDIR}/../../graphics/ImageMagick/files
PATCHDIR=	${.CURDIR}/../../graphics/ImageMagick/patches

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES

USE_PERL5=		run
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		auto/Image/Magick/.packlist

GNU_CONFIGURE=		YES

PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--with-perl=${PERL5}

post-configure: perl5-configure

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
