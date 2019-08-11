# $NetBSD: Makefile,v 1.16 2019/08/11 13:20:28 wiz Exp $
#

DISTNAME=	Test-CPAN-Meta-YAML-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-CPAN-Meta-YAML
COMMENT=	Perl 5 module to validate the META.yml file in a distribution
LICENSE=	artistic-2.0

BUILD_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=0.08:../../devel/p5-Test-Pod-Coverage

DEPENDS+=	p5-Test-YAML-Valid>=0.03:../../devel/p5-Test-YAML-Valid
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

PERL5_PACKLIST=	auto/Test/CPAN/Meta/YAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
