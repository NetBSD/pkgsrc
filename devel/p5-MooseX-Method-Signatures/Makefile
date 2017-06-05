# $NetBSD: Makefile,v 1.29 2017/06/05 14:23:20 ryoon Exp $
#

DISTNAME=	MooseX-Method-Signatures-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}
#MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Method-Signatures/
COMMENT=	Perl 5 module for method declarations with type constraints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.10:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-Context-Preserve-[0-9]*:../../devel/p5-Context-Preserve
DEPENDS+=	p5-Devel-Declare>=0.005011:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Moose>=0.89:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-LazyRequire>=0.06:../../devel/p5-MooseX-LazyRequire
DEPENDS+=	p5-MooseX-Meta-TypeConstraint-ForceCoercion-[0-9]*:../../devel/p5-MooseX-Meta-TypeConstraint-ForceCoercion
DEPENDS+=	p5-MooseX-Types>=0.35:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Structured>=0.24:../../devel/p5-MooseX-Types-Structured
DEPENDS+=	p5-Parse-Method-Signatures>=1.003014:../../devel/p5-Parse-Method-Signatures
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
DEPENDS+=	p5-Eval-Closure-[0-9]*:../../devel/p5-Eval-Closure
DEPENDS+=	p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime

BUILD_DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.89}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=	auto/MooseX/Method/Signatures/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
#BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
