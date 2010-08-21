# $NetBSD: Makefile,v 1.10 2010/08/21 16:35:12 seb Exp $

DISTNAME=	Math-FFT-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5fft
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-FFT/
COMMENT=	Perl module to calculate Fast Fourier Transforms

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/FFT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
