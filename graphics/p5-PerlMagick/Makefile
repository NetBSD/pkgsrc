# $NetBSD: Makefile,v 1.95 2013/06/03 10:05:18 wiz Exp $

.include "../../graphics/ImageMagick/Makefile.common"

PKGNAME=	p5-PerlMagick-${DISTVERSION}
PKGREVISION=	2
SVR4_PKGNAME=	p5pma

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.simplesystems.org/ImageMagick/www/perl-magick.html
COMMENT=	Object-oriented Perl interface to ImageMagick

DISTINFO_FILE=	${.CURDIR}/../../graphics/ImageMagick/distinfo
PATCHDIR=	${.CURDIR}/../../graphics/ImageMagick/patches

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
PERL5_PACKLIST=		auto/Image/Magick/.packlist
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

pre-configure:
	${LN} -sf ${WRKSRC}/PerlMagick/quantum/quantum.pm ${WRKSRC}/PerlMagick/quantum/Q16.pm
	${LN} -sf ${WRKSRC}/PerlMagick/quantum/quantum.xs ${WRKSRC}/PerlMagick/quantum/Q16.xs

post-configure: perl5-configure

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=${DISTVERSION}
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
