# $NetBSD: Makefile,v 1.122 2017/06/05 14:24:01 ryoon Exp $

PKGREVISION= 1
.include "../../graphics/ImageMagick/Makefile.common"

PKGNAME=	p5-PerlMagick-${DISTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.simplesystems.org/ImageMagick/www/perl-magick.html
COMMENT=	Object-oriented Perl interface to ImageMagick

DISTINFO_FILE=	${.CURDIR}/../../graphics/ImageMagick/distinfo
#PATCHDIR=	${.CURDIR}/../../graphics/ImageMagick/patches

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
PERL5_PACKLIST=		auto/Image/Magick/.packlist
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

pre-configure:
	${LN} -sf ${WRKSRC}/PerlMagick/quantum/quantum.pm ${WRKSRC}/PerlMagick/quantum/Q16HDRI.pm
	${LN} -sf ${WRKSRC}/PerlMagick/quantum/quantum.xs ${WRKSRC}/PerlMagick/quantum/Q16HDRI.xs

post-configure: perl5-configure

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=${DISTVERSION}
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
