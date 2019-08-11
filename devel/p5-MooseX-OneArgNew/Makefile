# $NetBSD: Makefile,v 1.16 2019/08/11 13:19:58 wiz Exp $
#

DISTNAME=	MooseX-OneArgNew-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-OneArgNew
COMMENT=	Moose role to teach ->new to accept single, non-hashref arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized>=1.01:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

#BUILD_DEPENDS+=	{perl>=5.14.0,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# for make test
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/OneArgNew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
