# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:32 wiz Exp $
#

DISTNAME=	Test-YAML-Valid-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-YAML-Valid
COMMENT=	Perl 5 module to test for valid YAML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML>=0.60:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=	p5-YAML-Syck>=0.60:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny

PERL5_PACKLIST=		auto/Test/YAML/Valid/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
