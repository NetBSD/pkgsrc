# $NetBSD: Makefile,v 1.9 2022/06/28 11:35:07 wiz Exp $

DISTNAME=	MaxMind-DB-Writer-0.300003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAXMIND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MaxMind-DB-Writer
COMMENT=	Create MaxMind DB database files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sereal-Decoder>=0:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder>=3.002:../../converters/p5-Sereal-Encoder
DEPENDS+=	p5-Data-Dumper-Concise>=0:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-Data-IEEE754>=0:../../devel/p5-Data-IEEE754
DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Params-Validate>=0:../../devel/p5-MooseX-Params-Validate
DEPENDS+=	p5-MooseX-StrictConstructor>=0:../../devel/p5-MooseX-StrictConstructor
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Math-Int64>=0.51:../../math/p5-Math-Int64
DEPENDS+=	p5-Math-Int128>=0.21:../../math/p5-Math-Int128
DEPENDS+=	p5-MaxMind-DB-Common>=0.031003:../../net/p5-MaxMind-DB-Common
DEPENDS+=	p5-MaxMind-DB-Reader>=0:../../net/p5-MaxMind-DB-Reader
DEPENDS+=	p5-Net-Works>=0:../../net/p5-Net-Works
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
TEST_DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
TEST_DEPENDS+=	p5-Data-Printer>=0:../../devel/p5-Data-Printer
TEST_DEPENDS+=	p5-Devel-Refcount>=0:../../devel/p5-Devel-Refcount
TEST_DEPENDS+=	p5-List-AllUtils>=0:../../devel/p5-List-AllUtils
TEST_DEPENDS+=	p5-Test-Bits>=0:../../devel/p5-Test-Bits
TEST_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-HexDifferences>=0:../../devel/p5-Test-HexDifferences
TEST_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/MaxMind/DB/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
