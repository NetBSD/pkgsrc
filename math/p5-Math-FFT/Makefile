# $NetBSD: Makefile,v 1.12 2012/09/11 23:04:27 asau Exp $

DISTNAME=	Math-FFT-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5fft
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-FFT/
COMMENT=	Perl module to calculate Fast Fourier Transforms

PERL5_PACKLIST=		auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
