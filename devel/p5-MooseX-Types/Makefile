# $NetBSD: Makefile,v 1.25 2013/10/31 08:33:48 wen Exp $
#

DISTNAME=	MooseX-Types-0.38
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types/
COMMENT=	Organise your Moose types in libraries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=6.00:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Moose>=1.06:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Install>=0.924:../../devel/p5-Sub-Install
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-namespace-clean>=0.19:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
