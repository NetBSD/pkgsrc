# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:30 tv Exp $

DISTNAME=	Math-FFT-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fft
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=       http://search.cpan.org/dist/Math-FFT/
COMMENT=	Perl module to calculate Fast Fourier Transforms

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
