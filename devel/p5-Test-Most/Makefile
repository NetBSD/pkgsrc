# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:42 obache Exp $
#

DISTNAME=	Test-Most-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Most
COMMENT=	Most commonly needed test functions and features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Deep>=0.106:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Differences>0.500:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Exception>0.29:../../devel/p5-Test-Exception
DEPENDS+=	{perl>=5.10.1,p5-Test-Harness>=3.07}:../../devel/p5-Test-Harness
DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Warn>0.11:../../devel/p5-Test-Warn

# recommended
DEPENDS+=	p5-Data-Dumper-Names>=0.03:../../devel/p5-Data-Dumper-Names

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Most/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
