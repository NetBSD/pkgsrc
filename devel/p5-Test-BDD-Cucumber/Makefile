# $NetBSD: Makefile,v 1.54 2021/09/13 07:45:50 schmonz Exp $

DISTNAME=		Test-BDD-Cucumber-0.82
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-BDD-Cucumber
COMMENT=		Feature-complete Cucumber-style testing in Perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-JSON-MaybeXS>=1.001000:../../converters/p5-JSON-MaybeXS
DEPENDS+=		p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=		p5-Moo>=2.002002:../../devel/p5-Moo
DEPENDS+=		p5-MooX-HandlesVia-[0-9]*:../../devel/p5-MooX-HandlesVia
DEPENDS+=		p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=		p5-Sub-Quote-[0-9]*:../../devel/p5-Sub-Quote
DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=		p5-YAML>=1.15:../../textproc/p5-YAML
DEPENDS+=		p5-strictures-[0-9]*:../../devel/p5-strictures

#BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	p5-Carp-Always-[0-9]*:../../devel/p5-Carp-Always
#BUILD_DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#BUILD_DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive

REPLACE_PERL+=		bin/pherkin
PERL5_PACKLIST=		auto/Test/BDD/Cucumber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
