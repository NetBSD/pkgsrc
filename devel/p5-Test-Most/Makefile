# $NetBSD: Makefile,v 1.13 2013/12/09 14:17:47 obache Exp $
#

DISTNAME=	Test-Most-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Most/
COMMENT=	Most commonly needed test functions and features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Deep>=0.106:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Differences>=0.6100:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Exception>=0.31:../../devel/p5-Test-Exception
DEPENDS+=	{perl>=5.14.2,p5-Test-Harness>=3.21}:../../devel/p5-Test-Harness
DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Warn>=0.23:../../devel/p5-Test-Warn

# recommended
DEPENDS+=	p5-Data-Dumper-Names>=0.03:../../devel/p5-Data-Dumper-Names

# XXX fix proving some kind of version setting via lang/perl5/module.mk
BUILD_DEPENDS+=	{perl>=5.17.1,p5-Module-Build>=0.40000}:../../devel/p5-Module-Build
PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Most/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
