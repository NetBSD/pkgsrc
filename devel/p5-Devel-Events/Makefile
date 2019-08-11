# $NetBSD: Makefile,v 1.20 2019/08/11 13:19:16 wiz Exp $

DISTNAME=	Devel-Events-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
DEPENDS+=	p5-MooseX-AttributeHelpers>=0.03:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-Set-Object-[0-9]*:../../devel/p5-Set-Object
DEPENDS+=	p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events.pm
CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
