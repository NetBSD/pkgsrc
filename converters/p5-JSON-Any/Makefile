# $NetBSD: Makefile,v 1.1.1.1 2007/09/07 12:43:17 abs Exp $

DISTNAME=		JSON-Any-1.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PERIGRIN/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON-Any/
COMMENT=		Wrapper Class for the various JSON classes

PERL5_PACKLIST=		auto/JSON/Any/.packlist

# Do not install any specific JSON converter - let user decide
# DEPENDS+=		p5-JSON-[0-9]*:../../converters/p5-JSON

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
