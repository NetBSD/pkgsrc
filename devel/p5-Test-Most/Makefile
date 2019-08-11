# $NetBSD: Makefile,v 1.26 2019/08/11 13:20:34 wiz Exp $

DISTNAME=	Test-Most-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Most
COMMENT=	Most commonly needed test functions and features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Deep>=0.119:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Differences>=0.6400:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Exception>=0.43:../../devel/p5-Test-Exception
#DEPENDS+=	{perl>=5.21.8,p5-Test-Harness>=3.35}:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-Simple>=0.1.302047:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Warn>=0.30:../../devel/p5-Test-Warn

# recommended
DEPENDS+=	p5-Data-Dumper-Names>=0.03:../../devel/p5-Data-Dumper-Names

# for make test
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Most/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
