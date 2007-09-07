# $NetBSD: Makefile,v 1.2 2007/09/07 12:54:45 abs Exp $

DISTNAME=		JSON-Any-1.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PERIGRIN/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON-Any/
COMMENT=		Wrapper Class for the various JSON classes

PERL5_PACKLIST=		auto/JSON/Any/.packlist

# May need to revisit this when multiple JSON converters in pkgsrc
DEPENDS+=		p5-JSON-[0-9]*:../../converters/p5-JSON

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
