# $NetBSD: Makefile,v 1.20 2022/06/28 11:31:30 wiz Exp $

DISTNAME=	Search-QueryParser-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAMI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Search-QueryParser
COMMENT=	Parses a query string into a data suitable for search engines
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Search/QueryParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
