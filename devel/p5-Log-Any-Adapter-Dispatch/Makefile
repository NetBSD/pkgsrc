# $NetBSD: Makefile,v 1.22 2023/07/06 09:39:26 wiz Exp $
#

DISTNAME=	Log-Any-Adapter-Dispatch-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any-Adapter
COMMENT=	Log::Any adapter uses Log::Dispatch for logging
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Log-Dispatch>=2.26:../../devel/p5-Log-Dispatch

# for make test
TOOL_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TOOL_DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio

PERL5_PACKLIST=		auto/Log/Any/Adapter/Dispatch/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
