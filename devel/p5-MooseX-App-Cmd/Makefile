# $NetBSD: Makefile,v 1.29 2022/06/28 11:32:51 wiz Exp $

DISTNAME=	MooseX-App-Cmd-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-App-Cmd
COMMENT=	Perl 5 module providing MooseX::Getopt and App::Cmd mashup
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/App/Cmd/.packlist

DEPENDS+=	p5-Any-Moose>=0:../../devel/p5-Any-Moose
DEPENDS+=	p5-App-Cmd>=0.321:../../devel/p5-App-Cmd
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.091:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Moose>=0.86:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Getopt>=0.18:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MouseX-Getopt>=0:../../devel/p5-MouseX-Getopt
DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean

TEST_DEPENDS+=	p5-MooseX-ConfigFromFile>=0.08:../../devel/p5-MooseX-ConfigFromFile
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
TEST_DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
TEST_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
TEST_DEPENDS+=	p5-MooseX-NonMoose-[0-9]*:../../devel/p5-MooseX-NonMoose
# for others
BUILD_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
