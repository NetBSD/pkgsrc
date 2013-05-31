# $NetBSD: Makefile,v 1.9 2013/05/31 12:41:23 wiz Exp $
#

DISTNAME=	Math-Random-MT-Perl-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Random-MT-Perl/
COMMENT=	Pure Perl Mersenne Twister Random Number Generator
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Math/Random/MT/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
