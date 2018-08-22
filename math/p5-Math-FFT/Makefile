# $NetBSD: Makefile,v 1.22 2018/08/22 09:45:38 wiz Exp $

DISTNAME=	Math-FFT-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-FFT/
COMMENT=	Perl module to calculate Fast Fourier Transforms
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
