# $NetBSD: Makefile,v 1.31 2023/12/17 06:02:24 mef Exp $

DISTNAME=	Log-Dispatchouli-3.007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Dispatchouli
COMMENT=	Perl 5 wrapper module around Log::Dispatch
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Log-Dispatch-Array-[0-9]*:../../devel/p5-Log-Dispatch-Array
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-String-Flogger-[0-9]*:../../textproc/p5-String-Flogger
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Exporter-GlobExporter>=0.002:../../devel/p5-Sub-Exporter-GlobExporter
DEPENDS+=	p5-Try-Tiny>=0.04:../../devel/p5-Try-Tiny

TEST_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=		p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TEST_DEPENDS+=		p5-Specio-[0-9]*:../../devel/p5-Specio
TEST_DEPENDS+=		p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler
#TEST_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Log/Dispatchouli/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
