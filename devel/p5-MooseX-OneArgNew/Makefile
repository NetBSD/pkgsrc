# $NetBSD: Makefile,v 1.7 2014/07/13 11:51:06 wen Exp $
#

DISTNAME=	MooseX-OneArgNew-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-OneArgNew/
COMMENT=	Moose role to teach ->new to accept single, non-hashref arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	{perl>=5.14.0,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/OneArgNew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
