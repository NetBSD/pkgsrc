# $NetBSD: Makefile,v 1.21 2022/06/28 11:33:12 wiz Exp $

DISTNAME=	Search-Elasticsearch-7.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Search-Elasticsearch
COMMENT=	Search::Elasticsearch - The official client for Elasticsearch
LICENSE=	apache-2.0

DEPENDS+=	p5-Any-URI-Escape-[0-9]*:../../www/p5-Any-URI-Escape
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Net-IP-[0-9]*:../../net/p5-Net-IP

TEST_DEPENDS+=	p5-Hijk-[0-9]*:../../www/p5-Hijk
TEST_DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
TEST_DEPENDS+=	p5-Log-Any-Adapter-Callback-[0-9]*:../../devel/p5-Log-Any-Adapter-Callback
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork

PERL5_PACKLIST=	auto/Search/Elasticsearch/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
