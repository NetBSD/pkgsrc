# $NetBSD: Makefile,v 1.6 2017/09/17 13:28:42 wiz Exp $

DISTNAME=		Test2-Suite-0.000077
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test2-Suite/
COMMENT=		Perl5 module with a rich set of tools for testing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Importer-[0-9]*:../../devel/p5-Importer
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=		p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
# TEST_DEPENDS
BUILD_DEPENDS+=		p5-Term-Table-[0-9]*:../../devel/p5-Term-Table

PERL5_PACKLIST=		auto/Test2/Suite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
