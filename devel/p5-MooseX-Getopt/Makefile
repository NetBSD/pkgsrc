# $NetBSD: Makefile,v 1.25 2013/10/02 14:38:16 wen Exp $
#

DISTNAME=	MooseX-Getopt-0.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Getopt/
COMMENT=	Perl 5 Moose role for processing command line options
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.081:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized

BUILD_DEPENDS+=	p5-Path-Tiny>=0.009:../../filesystems/p5-Path-Tiny
BUILD_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-CheckDeps>=0.002:../../devel/p5-Test-CheckDeps

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/MooseX/Getopt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
