# $NetBSD: Makefile,v 1.23 2018/08/22 09:44:52 wiz Exp $

DISTNAME=		Test2-Suite-0.000115
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test2-Suite/
COMMENT=		Perl5 module with a rich set of tools for testing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Importer-[0-9]*:../../devel/p5-Importer
DEPENDS+=		p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=		p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
DEPENDS+=		p5-Test-Simple>=1.302136:../../devel/p5-Test-Simple
DEPENDS+=		p5-Term-Table-[0-9]*:../../devel/p5-Term-Table
DEPENDS+=		p5-Scope-Guard-[0-9]*:../../devel/p5-Scope-Guard

PERL5_PACKLIST=		auto/Test2/Suite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
