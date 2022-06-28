# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:06 wiz Exp $

DISTNAME=	GeoIP2-2.006002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAXMIND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GeoIP2
COMMENT=	Perl API for MaxMind's GeoIP2 web services and databases
LICENSE=	artistic-2.0

DEPENDS+=	p5-JSON-MaybeXS>=0:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Data-Validate-IP>=0.25:../../devel/p5-Data-Validate-IP
DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Sub-Quote>=0:../../devel/p5-Sub-Quote
DEPENDS+=	p5-Throwable>=0:../../devel/p5-Throwable
DEPENDS+=	p5-Try-Tiny>=0:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-clean>=0:../../devel/p5-namespace-clean
DEPENDS+=	p5-MaxMind-DB-Reader>=1.0:../../net/p5-MaxMind-DB-Reader
DEPENDS+=	p5-List-SomeUtils>=0:../../devel/p5-List-SomeUtils
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message
DEPENDS+=	p5-LWP-Protocol-https>=0:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

TEST_DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
TEST_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Number-Delta>=0:../../math/p5-Test-Number-Delta
TEST_DEPENDS+=	p5-MaxMind-DB-Common>=0:../../net/p5-MaxMind-DB-Common
TEST_DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message

REPLACE_PERL=	bin/web-service-request

PERL5_PACKLIST=	auto/GeoIP2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
