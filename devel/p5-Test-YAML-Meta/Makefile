# $NetBSD: Makefile,v 1.2 2009/06/12 07:33:55 sno Exp $
#

DISTNAME=	Test-YAML-Meta-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML-Meta/
COMMENT=	Perl 5 module to validate the META.yml file in a distribution
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-YAML-Valid>=0.03:../../devel/p5-Test-YAML-Valid

BUILD_DEPENDS+=	p5-Test-Simple>0:../../devel/p5-Test-Simple
# These are recommended:
BUILD_DEPENDS+=	p5-Test-Pod>1.0:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=0.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-YAML>0:../../textproc/p5-YAML
BUILD_DEPENDS+=	p5-YAML-Syck>0:../../textproc/p5-YAML-Syck

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Test/YAML/Meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
