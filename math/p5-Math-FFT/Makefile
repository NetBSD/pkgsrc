# $NetBSD: Makefile,v 1.28 2022/06/28 11:34:40 wiz Exp $

DISTNAME=	Math-FFT-1.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-FFT
COMMENT=	Perl module to calculate Fast Fourier Transforms
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
