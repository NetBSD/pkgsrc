# $NetBSD: Makefile,v 1.9 2009/01/18 22:52:42 he Exp $

DISTNAME=		JSON-Any-1.19
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5 converters
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/JSON-Any/
COMMENT=		Wrapper Class for the various JSON classes

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/JSON/Any/.packlist

# p5-JSON-XS appears to be the current "best of breed"
DEPENDS+=		p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
