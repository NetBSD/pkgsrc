# $NetBSD: Makefile,v 1.10 2013/08/15 08:20:37 wen Exp $

DISTNAME=	Test-Aggregate-0.368
PKGNAME=	p5-${DISTNAME:S/363/36.3/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Aggregate/
COMMENT=	Aggregate *.t tests to make them run faster
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.1,p5-Test-Harness>=3.09}:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

# Recommends
DEPENDS+=	p5-Data-Dump-Streamer>=1.11:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-Perl-Tidy>=20060614:../../devel/p5-Perl-Tidy
DEPENDS+=	p5-Test-Simple>=0.94:../../devel/p5-Test-Simple

BUILD_DEPENDS+=	p5-Test-Most>=0.21:../../devel/p5-Test-Most
BUILD_DEPENDS+=	p5-Test-Simple>=0.94:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Test/Aggregate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
