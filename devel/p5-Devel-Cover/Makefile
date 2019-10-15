# $NetBSD: Makefile,v 1.38 2019/10/15 14:30:52 mef Exp $

DISTNAME=	Devel-Cover-1.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Cover
COMMENT=	Perl 5 module providing code coverage metrics
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PPI-HTML>=1.07:../../textproc/p5-PPI-HTML
DEPENDS+=	p5-Perl-Tidy>=20060719:../../devel/p5-Perl-Tidy
DEPENDS+=	p5-Sereal-[0-9]*:../../converters/p5-Sereal
DEPENDS+=	p5-Pod-Coverage>=0.06:../../textproc/p5-Pod-Coverage
DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

TEST_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TEST_DEPENDS+=	p5-B-Debug-[0-9]*:../../devel/p5-B-Debug

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/Cover/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
