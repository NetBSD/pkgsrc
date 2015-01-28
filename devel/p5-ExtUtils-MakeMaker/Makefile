# $NetBSD: Makefile,v 1.33 2015/01/28 03:07:24 mef Exp $

DISTNAME=	ExtUtils-MakeMaker-7.05_10
PKGNAME=	p5-${DISTNAME:S/_/./}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BI/BINGOS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-MakeMaker
COMMENT=	Create a module Makefile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Manifest>=1.65:../../devel/p5-ExtUtils-Manifest

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
