# $NetBSD: Makefile,v 1.24 2026/08/13 07:45:21 wiz Exp $

DISTNAME=	Net-CIDR-Set-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRWO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-CIDR-Set
COMMENT=	Perl 5 module to manipulate sets of IP addresses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/CIDR/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
