# $NetBSD: Makefile,v 1.5 2005/08/06 06:19:23 jlam Exp $

DISTNAME=	Math-FFT-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fft
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=       http://search.cpan.org/dist/Math-FFT/
COMMENT=	Perl module to calculate Fast Fourier Transforms

PERL5_PACKLIST=		auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
