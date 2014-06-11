# $NetBSD: Makefile,v 1.1 2014/06/11 20:50:39 schmonz Exp $

DISTNAME=		Number-Range-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Range/
COMMENT=		Define ranges and test if number is in range
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
