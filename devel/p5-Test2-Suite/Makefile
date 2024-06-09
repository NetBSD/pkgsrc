# $NetBSD: Makefile,v 1.49 2024/06/09 06:12:23 wiz Exp $

DISTNAME=		Test2-Suite-0.000163
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Suite
COMMENT=		Perl5 module with a rich set of tools for testing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Importer>=0.024:../../devel/p5-Importer
DEPENDS+=		p5-Module-Pluggable>=2.7:../../devel/p5-Module-Pluggable
DEPENDS+=		p5-Term-Table>=0.013:../../devel/p5-Term-Table
TEST_DEPENDS+=		p5-Term-Size-Any-[0-9]*:../../devel/p5-Term-Size-Any
TEST_DEPENDS+=		p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS

PERL5_PACKLIST=		auto/Test2/Suite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
