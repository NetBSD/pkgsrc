# $NetBSD: Makefile,v 1.8 2016/06/19 12:06:07 mef Exp $

DISTNAME=	Search-Elasticsearch-2.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/D/DR/DRTECH/
#ASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/D/DR/DRTECH/
COMMENT=	Search::Elasticsearch - The official client for Elasticsearch
LICENSE=	apache-2.0

# for make test, but not completed yet
BUILD_DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
BUILD_DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
BUILD_DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
BUILD_DEPENDS+=	p5-Hijk-[0-9]*:../../www/p5-Hijk
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
BUILD_DEPENDS+=	p5-Any-URI-Escape-[0-9]*:../../www/p5-Any-URI-Escape

PERL5_PACKLIST=	auto/Search/Elasticsearch/.packlist
USE_LANGUAGES=	# none

TEST_TARGET?=	# empty = means make test fails

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
