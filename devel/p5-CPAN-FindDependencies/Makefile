# $NetBSD: Makefile,v 1.30 2023/12/13 13:20:42 mef Exp $

DISTNAME=	CPAN-FindDependencies-3.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-FindDependencies
COMMENT=	Perl 5 module to find dependencies for modules on the CPAN
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.05:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Devel-CheckOS>=1.52:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-Env-Path>=0.19:../../devel/p5-Env-Path
#DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.19}:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Type>=0:../../devel/p5-File-Type
DEPENDS+=	p5-libwww>=1.41:../../www/p5-libwww
DEPENDS+=	p5-Parse-CPAN-Packages>=2.31:../../devel/p5-Parse-CPAN-Packages
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI # really URI::file>=4.13
DEPENDS+=	p5-YAML-Tiny>=1.36:../../textproc/p5-YAML-Tiny

TEST_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
# for Types::Standard
TEST_DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
TEST_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TEST_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
TEST_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TEST_DEPENDS+=	p5-Test-Time-[0-9]*:../../time/p5-Test-Time

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/FindDependencies/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
