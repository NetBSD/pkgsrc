# $NetBSD: Makefile,v 1.66 2019/06/30 20:15:28 nia Exp $

DISTNAME=	Mouse-v2.5.6
PKGNAME=	p5-${DISTNAME:S/v//1}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKAJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mouse
COMMENT=	Perl module implementing an extension of the perl object system
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires>=0.06:../../devel/p5-Test-Requires
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
#BUILD_DEPENDS+=	{perl>=5.14.1,p5-ExtUtils-ParseXS>=2.21}:../../devel/p5-ExtUtils-ParseXS
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Devel-PPPort>=3.19}:../../devel/p5-Devel-PPPort
BUILD_DEPENDS+=	p5-Module-Build-XSUtil>=0:../../devel/p5-Module-Build-XSUtil
# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
# (recommended)
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
BUILD_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
BUILD_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage

MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=		auto/Mouse/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
