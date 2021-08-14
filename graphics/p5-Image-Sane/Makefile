# $NetBSD: Makefile,v 1.1 2021/08/14 14:58:27 bsiegert Exp $

DISTNAME=	Image-Sane-5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/R/RA/RATCLIFFE/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Image::Sane
COMMENT=	Perl extension for the SANE (Scanner Access Now Easy)

.include "../../lang/perl5/license.mk"
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=0:../../devel/p5-Exception-Class
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly

PERL5_PACKLIST=	auto/Image/Sane/.packlist

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
