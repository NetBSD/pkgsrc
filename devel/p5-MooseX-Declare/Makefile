# $NetBSD: Makefile,v 1.29 2019/08/11 13:19:57 wiz Exp $
#

DISTNAME=	MooseX-Declare-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Declare
COMMENT=	Perl 5 module providing declarative syntax for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Declare>=0.005011:../../devel/p5-Devel-Declare
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=0.90:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Method-Signatures>=0.36:../../devel/p5-MooseX-Method-Signatures
DEPENDS+=	p5-MooseX-Role-Parameterized>=0.12:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-MooseX-Types>=0.20:../../devel/p5-MooseX-Types
DEPENDS+=	p5-namespace-autoclean>=0.16:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-CheckDeps>=0.007:../../devel/p5-Test-CheckDeps

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/MooseX/Declare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
