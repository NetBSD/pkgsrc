# $NetBSD: Makefile,v 1.30 2023/08/31 23:14:47 wen Exp $

DISTNAME=	Log-Dispatchouli-3.006
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

TOOL_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=		p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TOOL_DEPENDS+=		p5-Specio-[0-9]*:../../devel/p5-Specio
TOOL_DEPENDS+=		p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler
#TOOL_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Log/Dispatchouli/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
