# $NetBSD: Makefile,v 1.14 2018/08/22 09:44:51 wiz Exp $
#

DISTNAME=	Test-YAML-Valid-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML-Valid/
COMMENT=	Perl 5 module to test for valid YAML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML>=0.60:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=	p5-YAML-Syck>=0.60:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny

PERL5_PACKLIST= 	auto/Test/YAML/Valid/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
