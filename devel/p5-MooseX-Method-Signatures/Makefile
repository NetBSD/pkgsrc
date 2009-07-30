# $NetBSD: Makefile,v 1.1.1.1 2009/07/30 23:02:58 seb Exp $
#

DISTNAME=	MooseX-Method-Signatures-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Method-Signatures/
COMMENT=	Perl 5 module for method declarations with type constraints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope>=0.07:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-Context-Preserve-[0-9]*:../../devel/p5-Context-Preserve
DEPENDS+=	p5-Devel-Declare>=0.003004:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Moose>=0.63:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Meta-TypeConstraint-ForceCoercion-[0-9]*:../../devel/p5-MooseX-Meta-TypeConstraint-ForceCoercion
DEPENDS+=	p5-MooseX-Types>=0.09:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Structured>=0.12:../../devel/p5-MooseX-Types-Structured
DEPENDS+=	p5-Parse-Method-Signatures>=1.003004:../../devel/p5-Parse-Method-Signatures
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=	auto/MooseX/Method/Signatures/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
