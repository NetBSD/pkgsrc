# $NetBSD: Makefile,v 1.25 2022/06/28 11:32:43 wiz Exp $

DISTNAME=	MetaCPAN-API-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MetaCPAN-API
COMMENT=	Comprehensive, DWIM-featured API to MetaCPAN for Perl5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-TinyMocker-[0-9]*:../../devel/p5-Test-TinyMocker
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
BUILD_DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
BUILD_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet

PERL5_PACKLIST=		auto/MetaCPAN/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
