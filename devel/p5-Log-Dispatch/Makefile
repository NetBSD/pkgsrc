# $NetBSD: Makefile,v 1.65 2019/08/11 13:19:44 wiz Exp $

DISTNAME=	Log-Dispatch-2.68
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Dispatch
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	artistic-2.0

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio

TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
