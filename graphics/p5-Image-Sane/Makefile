# $NetBSD: Makefile,v 1.4 2022/06/28 11:34:06 wiz Exp $

DISTNAME=	Image-Sane-5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/R/RA/RATCLIFFE/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Image::Sane
COMMENT=	Perl extension for the SANE (Scanner Access Now Easy)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=0:../../devel/p5-Exception-Class
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly
BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends
BUILD_DEPENDS+=	p5-ExtUtils-PkgConfig-[0-9]*:../../devel/p5-ExtUtils-PkgConfig
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TEST_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

PERL5_PACKLIST=	auto/Image/Sane/.packlist

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
