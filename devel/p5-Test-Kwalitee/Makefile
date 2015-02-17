# $NetBSD: Makefile,v 1.9 2015/02/17 06:33:45 mef Exp $
#

DISTNAME=		Test-Kwalitee-1.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Kwalitee/
COMMENT=		Perl5 module to test the Kwalitee of a distribution
LICENSE=		${PERL5_LICENSE}

DEPENDS+=  		p5-Module-CPANTS-Analyse>=0.82:../../devel/p5-Module-CPANTS-Analyse
DEPENDS+=		p5-Test-Warnings>=0:../../devel/p5-Test-Warnings
DEPENDS+=		p5-CPAN-Meta-Check>=0:../../devel/p5-CPAN-Meta-Check

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Kwalitee/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
