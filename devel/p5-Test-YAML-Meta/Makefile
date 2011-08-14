# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:45 obache Exp $
#

DISTNAME=	Test-YAML-Meta-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML-Meta/
COMMENT=	Perl 5 module to validate the META.yml file in a distribution
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-YAML-Valid>=0.03:../../devel/p5-Test-YAML-Valid

# These are recommended:
BUILD_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=0.08:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-Test-YAML-Valid>=0.03:../../devel/p5-Test-YAML-Valid
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Test/YAML/Meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
