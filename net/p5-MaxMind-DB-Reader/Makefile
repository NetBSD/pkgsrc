# $NetBSD: Makefile,v 1.12 2022/06/28 11:35:07 wiz Exp $

DISTNAME=	MaxMind-DB-Reader-1.000014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAXMIND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MaxMind-DB-Reader
COMMENT=	Read MaxMind DB files and look up IP addresses
LICENSE=	artistic-2.0

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-Data-IEEE754>=0:../../devel/p5-Data-IEEE754
DEPENDS+=	p5-Data-Printer>=0:../../devel/p5-Data-Printer
DEPENDS+=	p5-Data-Validate-IP>=0.25:../../devel/p5-Data-Validate-IP
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-List-AllUtils>=0:../../devel/p5-List-AllUtils
DEPENDS+=	p5-Math-BigInt>=0:../../math/p5-Math-BigInt
DEPENDS+=	p5-MaxMind-DB-Common>=0.040001:../../net/p5-MaxMind-DB-Common
DEPENDS+=	p5-Module-Implementation>=0:../../devel/p5-Module-Implementation
DEPENDS+=	p5-Moo>=1.003000:../../devel/p5-Moo
DEPENDS+=	p5-MooX-StrictConstructor>=0:../../devel/p5-MooX-StrictConstructor
DEPENDS+=	p5-Role-Tiny>=1.003002:../../devel/p5-Role-Tiny
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean
TEST_DEPENDS+=	p5-Path-Class>=0.27:../../devel/p5-Path-Class
TEST_DEPENDS+=	p5-Test-Bits>=0:../../devel/p5-Test-Bits
TEST_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Number-Delta>=0:../../math/p5-Test-Number-Delta
TEST_DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-MaxMind-DB-Common>=0:../../net/p5-MaxMind-DB-Common

REPLACE_PERL=	bin/mmdb-dump-metadata
REPLACE_PERL+=	bin/mmdb-dump-search-tree

PERL5_PACKLIST=	auto/MaxMind/DB/Reader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
