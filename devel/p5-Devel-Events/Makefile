# $NetBSD: Makefile,v 1.28 2026/01/18 09:18:49 wen Exp $

DISTNAME=	Devel-Events-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Events
COMMENT=	Perl 5 module providing an extensible instrumentation framework
LICENSE=	mit OR ${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Events/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-Moose>=0.33:../../devel/p5-Moose
DEPENDS+=	p5-Set-Object-[0-9]*:../../devel/p5-Set-Object
DEPENDS+=	p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events.pm
CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
