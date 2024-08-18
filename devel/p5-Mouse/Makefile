# $NetBSD: Makefile,v 1.76 2024/08/18 08:12:44 wen Exp $

DISTNAME=	Mouse-v2.5.11
PKGNAME=	p5-${DISTNAME:S/v//1}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKAJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mouse
COMMENT=	Perl module implementing an extension of the perl object system
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Requires>=0.06:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-Module-Build-XSUtil>=0:../../devel/p5-Module-Build-XSUtil

# for make test
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
# (recommended)
TEST_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
TEST_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
TEST_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
TEST_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Params-Coerce-[0-9]*:../../devel/p5-Params-Coerce

MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=		auto/Mouse/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
