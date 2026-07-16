# $NetBSD: Makefile,v 1.21 2026/07/16 19:02:56 wiz Exp $
#

DISTNAME=	MooseX-Meta-TypeConstraint-ForceCoercion-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Meta-TypeConstraint-ForceCoercion
COMMENT=	Perl 5 module providing forced coercion validating type constraints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Meta/TypeConstraint/ForceCoercion/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
