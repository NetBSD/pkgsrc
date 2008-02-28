# $NetBSD: Makefile,v 1.4 2008/02/28 09:15:12 abs Exp $

DISTNAME=		JSON-Any-1.16
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PERIGRIN/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON-Any/
COMMENT=		Wrapper Class for the various JSON classes

PERL5_PACKLIST=		auto/JSON/Any/.packlist

# p5-JSON-XS appears to be the current "best of breed"
DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
