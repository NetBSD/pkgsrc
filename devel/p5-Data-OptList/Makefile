# $NetBSD: Makefile,v 1.32 2026/09/12 20:38:08 wiz Exp $

DISTNAME=	Data-OptList-0.115
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-OptList
COMMENT=	Parse and validate simple name/value option pairs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-SomeUtil>=0:../../devel/p5-Params-SomeUtil
DEPENDS+=	p5-Sub-Install>=0.921:../../devel/p5-Sub-Install

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/OptList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
