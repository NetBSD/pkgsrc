# $NetBSD: Makefile,v 1.39 2018/08/21 11:11:36 wiz Exp $

DISTNAME=	MooseX-Getopt-0.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Getopt
COMMENT=	Moose role for processing command line options
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.088:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

TEST_DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
TEST_DEPENDS+=	p5-Path-Tiny>=0.009:../../filesystems/p5-Path-Tiny
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Kwalitee>=1.12:../../devel/p5-Test-Kwalitee
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-Pod>=1.41:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
TEST_DEPENDS+=	p5-Test-Warnings>=0.009:../../devel/p5-Test-Warnings
# recommended modules ...
#BUILD_DEPENDS+=	p5-CPAN-Meta-[0-9]*:../../devel/p5-CPAN-Meta
#BUILD_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.120900:../../devel/p5-CPAN-Meta-Requirements
#BUILD_DEPENDS+=	p5-MooseX-ConfigFromFile-[0-9]*:../../devel/p5-MooseX-ConfigFromFile
#BUILD_DEPENDS+=	p5-MooseX-SimpleConfig>=0.07:../../devel/p5-MooseX-SimpleConfig

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=	auto/MooseX/Getopt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
