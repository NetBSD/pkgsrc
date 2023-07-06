# $NetBSD: Makefile,v 1.20 2023/07/06 09:40:11 wiz Exp $

DISTNAME=	Test-DependentModules-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::DependentModules
COMMENT=	Test all modules which depend on your module
LICENSE=	artistic-2.0

# for make test
TOOL_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TOOL_DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
TOOL_DEPENDS+=	p5-IO-Handle-Util-[0-9]*:../../devel/p5-IO-Handle-Util
TOOL_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
TOOL_DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
TOOL_DEPENDS+=	p5-Module-Build-Tiny-[0-9]*:../../devel/p5-Module-Build-Tiny
TOOL_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TOOL_DEPENDS+=	p5-MetaCPAN-Client-[0-9]*:../../devel/p5-MetaCPAN-Client
TOOL_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
TOOL_DEPENDS+=	p5-Search-Elasticsearch-[0-9]*:../../devel/p5-Search-Elasticsearch
TOOL_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TOOL_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
TOOL_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TOOL_DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
TOOL_DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio
TOOL_DEPENDS+=	p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler

PERL5_PACKLIST=	auto/Test/DependentModules/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
